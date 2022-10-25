#pragma once


#ifndef CUSTMALLOCATOR_H
#define CUSTMALLOCATOR_H

#include <memory>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <numeric>
#include <limits>

#define deafultBlocks 100

template<class T>
class allocator
{
public:
    using value_type = T;
    using size_type = std::size_t;
    using pointer = T*;
    using const_pointer = const T*;
    using difference_type = typename std::pointer_traits<pointer>::difference_type;

    struct chunk
    {
        std::vector<void*>free_chunks;
        size_t size = 0;
    };

    allocator()
    {
        std::vector<size_t> other(deafultBlocks);

        std::vector<size_t> groups(other);
        std::sort(groups.begin(), groups.end());
        std::vector<size_t> groups_copy(groups);

        unsigned long long groups_cnt = std::unique(groups_copy.begin(), groups_copy.end()) - groups_copy.begin();
        memory_list = new std::vector<chunk>(groups_cnt);

        unsigned long long total_size_of_memory = groups.end() - groups.begin();
        total_size_of_memory += groups.size() * sizeof(size_t);
        memory_begin = malloc(total_size_of_memory);
    }

    explicit allocator(const std::vector<size_t>& other)
    {
        memory_alloc(other);
    }

    allocator(const allocator<T>& other) noexcept :
        memory_begin(other.memory_begin),
        memory_list(other.memory_list)
    {};

    template<typename U>
    explicit allocator(const allocator<U>& other) noexcept
    {
        this->memory_begin = other.memory_begin;
        this->memory_list = other.memory_list;
    }

    ~allocator() = default;

    value_type* allocate(size_t n)
    {
        for (size_t i = 0; i < (*memory_list).size(); ++i)
        {
            if ((*memory_list)[i].size >= n * sizeof(value_type) && !(*memory_list)[i].free_chunks.empty())
            {
                void* memory_block = (*memory_list)[i].free_chunks[(*memory_list)[i].free_chunks.size() - 1];
                (*memory_list)[i].free_chunks.pop_back();

                return (value_type*)memory_block;
            }
        }

        throw std::bad_alloc();
    }

    void deallocate(value_type* p, size_t size = 0) noexcept
    {
        size_t chunk_size = *((size_t*)p - 1); // Смотрим размер чанка, который принадлежит указателю

        for (size_t i = 0; i < (*memory_list).size(); ++i)
        {
            if ((*memory_list)[i].size == chunk_size)
            {
                (*memory_list)[i].free_chunks.push_back(p);

                return;
            }
        }
    }

    template<typename U>
    struct rebind {
        using other = allocator<U>; //преведение типов
    };

    bool operator==(const allocator& other) noexcept
    {
        return this->memory_list == other.memory_list;
    }

    bool operator!=(const allocator& other) noexcept
    {
        return *this != other;
    }

private:
    pointer memory_list;
    pointer memory_begin = nullptr;

    // Выделение памяти
    void memory_alloc(const std::vector<size_t>& other)
    {
        // Считаем количество групп и задаем в вектор их кол-во
        std::vector<size_t> groups(other);
        std::sort(groups.begin(), groups.end());
        std::vector<size_t> groups_copy(groups);

        unsigned long long groups_cnt = std::unique(groups_copy.begin(), groups_copy.end()) - groups_copy.begin();
        memory_list = new std::vector<chunk>(groups_cnt);

        // Выделяем память сразу под все параметры
        unsigned long long total_size_of_memory = groups.end() - groups.begin();
        total_size_of_memory += groups.size() * sizeof(size_t);
        memory_begin = malloc(total_size_of_memory);

        if (memory_begin == nullptr)
            throw std::bad_alloc();

        int shift = 0; // Сдвиг в памяти
        int groupNum = 0; // Номер группы
        size_t cur_size = groups[0]; // Текущий параметр

        for (auto element : groups)
        {
            if (cur_size != element)
            {
                // Обозначаем, какие размеры в данной группе
                (*memory_list)[groupNum].size = cur_size;

                // Сдвигаемся в след. группу и меняем текущий размер
                groupNum++;
                cur_size = element;
            }

            *(reinterpret_cast<size_t*> ((char*)memory_begin.get() + shift)) = cur_size; // Помечаем сколько хранит данный чанк
            (*memory_list)[groupNum].free_chunks.push_back(static_cast<char*>(memory_begin.get()) + shift + sizeof(size_t)); // Сохраняем чанк в вектор со свободной памятью

            shift += cur_size + sizeof(size_t);
        }

        (*memory_list)[groupNum].size = cur_size;
    }
};

#endif
