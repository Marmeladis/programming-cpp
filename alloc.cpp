#include "alloc.h"

#include <iostream>

alloc::alloc(size_t n, size_t sz) : block_num(n), block_size(sz)
{
    allpool = operator new(all_size);
    if (allpool != nullptr)
    {
        for (auto i = 0; i < block_num; ++i)
        {
           
            block_ptr* curr = new (static_cast<char*>(allpool) + i * (block_size + sizeof(block))) block_ptr;
            block_ptr new_curr = *curr;
            new_curr->prev = nullptr;
            new_curr->next = freeBlock;

            if (freeBlock != nullptr)
            {
                freeBlock->prev = new_curr;
            }

            freeBlock = new_curr;
            delete new_curr;
        }
    }
}

alloc::alloc() : alloc(64, 1024)
{
}

alloc::alloc(const std::vector<int>& n_blocks, const std::vector<int>& sz_blocks)
{
    if (n_blocks.size() != sz_blocks.size())
        throw std::invalid_argument("Invalid argument of vector!");

    allpool = operator new(all_size);
    if (allpool != nullptr)
    {
        for (auto i = 0; i < n_blocks.size(); i++)
        {
            block_num = n_blocks[i];
            block_size = sz_blocks[i];

            for (auto j = 0; j < block_num; j++)
            {
                //block_ptr curr = reinterpret_cast<block_ptr>(static_cast<char *>(allpool) + j * (block_size + sizeof(block)));
                block_ptr* curr = new (static_cast<char*>(allpool) + i * (block_size + sizeof(block))) block_ptr;
                block_ptr new_curr = *curr;
                new_curr->prev = nullptr;
                new_curr->next = freeBlock;

                if (freeBlock != nullptr)
                {
                    freeBlock->prev = new_curr;
                }

                freeBlock = new_curr;
                delete new_curr;
            }
        }
    }
}

void* alloc::allocate(size_t sz)
{
    if (sz > block_size || freeBlock == nullptr || allpool == nullptr)
        throw std::invalid_argument("You can't allocate");

    block_ptr curr = freeBlock;

    freeBlock = curr->next;
    if (freeBlock != nullptr)
    {
        freeBlock->prev = nullptr;
    }

    curr->next = allocBlock;
    if (allocBlock != nullptr)
    {
        allocBlock->prev = curr;
    }
    allocBlock = curr;

    return static_cast<void*>(reinterpret_cast<char*>(curr) + sizeof(block));
}

void alloc::deallocate(void* ptr, size_t sz)
{
    if (allpool < ptr && ptr < (void*)((char*)allpool + all_size))
    {
        block_ptr curr = reinterpret_cast<block_ptr>(static_cast<char*>(ptr) - sizeof(block));

        allocBlock = curr->next;
        if (allocBlock != nullptr)
        {
            allocBlock->prev = nullptr;
        }

        curr->next = freeBlock;
        if (freeBlock != nullptr)
        {
            freeBlock->prev = curr;
        }
        freeBlock = curr;
    }
    else
        operator delete(ptr);
}

alloc::~alloc()
{
    if (allpool != nullptr)
        operator delete(allpool);
}