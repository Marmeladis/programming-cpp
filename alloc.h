#pragma once
#pragma once

#ifndef ALLOC_H
#define ALLOC_H

#include <stdio.h>
#include <sdkddkver.h>
#include <vector>
#include <exception>
#include <new>

class alloc
{
public:
    alloc();
    alloc(size_t n, size_t sz);
    alloc(const std::vector<int>& n_blocs, const std::vector<int>& sz_blocks);
    void* allocate(size_t sz);
    void deallocate(void* ptr, size_t = 0);
    ~alloc();

private:
    struct block
    {
        struct block* prev = nullptr, * next = nullptr;
    };

    typedef struct block* block_ptr;
    void* allpool = nullptr;        // address of the whole pool
    block_ptr freeBlock = nullptr;  // free memory block linked list
    block_ptr allocBlock = nullptr; // alloced memory black linked list

    size_t block_size;
    size_t block_num;
    size_t all_size = block_num * (block_size + sizeof(block));
};

#endif
