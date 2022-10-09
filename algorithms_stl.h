#pragma once
#ifndef CODE_ALGORITHMS_STL_H
#define CODE_ALGORITHMS_STL_H

#include <iostream>
#include <algorithm>

namespace algorithms_stl
{
    template <typename T, class UnaryPredicate>
    bool all_of(T begin, T end, UnaryPredicate predicate)
    {
        while (begin != end)
        {
            if (!predicate(*begin))
                return false;
            ++begin;
        }
        return true;
    }

    template <typename T, class UnaryPredicate>
    bool any_of(T begin, T end, UnaryPredicate predicate)
    {
        while (begin != end)
        {
            if (predicate(*begin))
                return true;
            ++begin;
        }
        return false;
    }

    template <typename T, class UnaryPredicate>
    bool none_of(T begin, T end, UnaryPredicate predicate)
    {
        return !(algorithms_stl::any_of(begin, end, predicate));
    }

    template <typename T, class UnaryPredicate>
    bool one_of(T begin, T end, UnaryPredicate predicate)
    {
        short count = 0;
        while (begin != end)
        {
            if (predicate(*begin))
                count++;
            ++begin;
            if (count >= 2)
                return false;
        }
        return count == 1;
    }

    template <typename T, class Compare>
    bool is_sorted(T begin, T end, Compare comp)
    {
        if (begin == end)
            return true;
        end--;
        for (T it = begin; it != end; ++it)
        {
            if (comp(*(it), *(++begin)))
                return true;
        }
        return false;
    }

    template <typename T, class Compare>
    bool is_partitioned(T begin, T end, Compare comp)
    {
        while (begin != end && comp(*begin))
            ++begin;
        while (begin != end)
        {
            if (comp(*begin))
                return false;
            ++begin;
        }
        return true;
    }

    template <typename T, typename E>
    T find_not(T begin, T end, const E el)
    {
        while (begin != end)
        {
            if ((*begin) != el)
                return begin;
            ++begin;
        }
        return end;
    }

    template <typename T, typename E>
    T find_backward(T begin, T end, E el)
    {
        while (begin != end)
        {
            --end;
            if ((*end) == el)
                return end;
        }
        return begin;
    }

    template <typename T, class Compare>
    bool is_palindrome(T begin, T end, Compare comp)
    {
        if (begin == end)
            return true;
        --end;
        while (begin != end)
        {
            if (comp(*begin) != comp(*end))
                return false;
            ++begin;
            if (begin == end)
                return true;
            --end;
        }
        return true;
    }
}

#endif
