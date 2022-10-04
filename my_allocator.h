#pragma once
#ifndef MY_ALLOC_H
#define MY_ALLOC_H

#include <limits>

#include "alloc.h"

template <typename T>
class my_alloc
{
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;

    my_alloc() = default;
    my_alloc(const my_alloc&) {}

    template <typename U>
    my_alloc(const my_alloc<U>& other) {}

    my_alloc& operator=(const my_alloc&) = delete;
    ~my_alloc() = default;

    static pointer address(reference r)
    {
        return &r;
    }

    static const_pointer address(const_reference cr)
    {
        return &cr;
    }

    static size_type max_size()
    {
        return std::numeric_limits<size_type>::max();
    }

    bool operator==(const my_alloc&) const
    {
        return true;
    }
    bool operator!=(const my_alloc&) const
    {
        return false;
    }

    pointer allocate(size_type n)
    {
        return static_cast<pointer>(memp.allocate(sizeof(T) * n));
    }

    pointer allocate(size_type n, pointer ptr)
    {
        return allocate(n);
    }

    void deallocate(pointer ptr, size_type n)
    {
        memp.deallocate(ptr, n);
    }

    static void construct(pointer ptr, const value_type& t)
    {
        new (ptr) value_type(t);
    }

    static void destroy(pointer ptr)
    {
        ptr->~value_type();
    }

private:
    alloc memp;
};

#endif
