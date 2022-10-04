#pragma once
#ifndef LAB3_ITERATOR_FOR_CB_H
#define LAB3_ITERATOR_FOR_CB_H

#include <iterator>
#include <memory>
#include <iostream>
#include <algorithm>

template <class T>
class ra_iterator : public std::iterator<std::random_access_iterator_tag, T>
{
private:
    T *begin_;
    T *end_;
    T *head_;
    T *curr_;

public:
    ra_iterator() : begin_(nullptr), end_(nullptr), head_(nullptr), curr_(nullptr) {}

    ra_iterator(T *begin, T *end, T *head, T *curr) : begin_(begin), end_(end), head_(head), curr_(curr) {}

    ra_iterator(const ra_iterator &it) : begin_(it.begin_), end_(it.end_), head_(it.head_), curr_(it.curr_) {}

    ra_iterator &operator=(const ra_iterator &other) noexcept
    {
        if (this == other)
            return *this;
        this->begin_ = other.begin_;
        this->curr_ = other.curr_;
        this->end_ = other.end_;
        return *this;
    }

    ra_iterator &operator+=(const int n) noexcept
    {
        if (n < 0)
            return *this -= -n;
        for (int i = 0; i < n; i++)
        {
            ++curr_;
            if (curr_ == end_)
                curr_ = begin_;
        }
        return *this;
    }

    ra_iterator &operator-=(const int n) noexcept
    {
        if (n < 0)
            return *this += -n;
        for (int i = 0; i < n; i++)
        {
            --curr_;
            if (curr_ == begin_)
                curr_ = end_;
        }
        return *this;
    }

    ra_iterator &operator++() noexcept
    {
        ++curr_;
        if (curr_ == end_)
            curr_ = begin_;
        return *this;
    }

    ra_iterator &operator--() noexcept
    {
        if (curr_ == begin_)
            curr_ = end_;
        --curr_;
        return *this;
    }

    ra_iterator operator+(const int n) const
    {
        ra_iterator iter(*this);
        iter += n;
        return iter;
    }

    ra_iterator operator-(const int n) const
    {
        ra_iterator iter(*this);
        iter -= n;
        return iter;
    }

    T &operator*() const
    {
        return *curr_;
    }

    T *operator->() const
    {
        return curr_;
    }

private:
    size_t poz(const ra_iterator &I) const
    {
        size_t n = 0;
        T *cur = I.head_;
        while (cur != I.curr_)
        {
            if (cur == I.end_)
                cur = I.begin_;
            ++n;
            ++cur;
        }
        return n;
    }

public:
    inline bool operator!=(const ra_iterator &I) const { return curr_ != I.curr_; }

    inline bool operator==(const ra_iterator &I) const { return curr_ == I.curr_; }

    inline bool operator>(const ra_iterator &I) const { return poz(*this) > poz(I); }

    inline bool operator<(const ra_iterator &I) const { return poz(*this) < poz(I); }

    inline bool operator<=(const ra_iterator &I) const { return !(*this > I); }

    inline bool operator>=(const ra_iterator &I) const { return !(*this < I); }
};

#endif
