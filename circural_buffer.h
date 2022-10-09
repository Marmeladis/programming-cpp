#pragma once
#ifndef LAB3_CIRCULAR_BUFFER_H
#define LAB3_CIRCULAR_BUFFER_H

#include "iterator_for_cb.h"

template <typename T, class Alloc = std::allocator<T>>
class circular_buffer
{
public:
    using alloc_type = Alloc;
    using alloc_traits = std::allocator_traits<Alloc>;

private:
    T* _buff;
    size_t _n;
    size_t _capacity;
    T* _head;
    T* _end;
    T* _begin;
    alloc_type _alloc;

    void plusplus(T*& curr)
    {
        ++curr;
        if (curr == _begin + _n + 1)
            curr = _begin;
    }

    void minusminus(T*& curr)
    {
        if (curr == _begin)
            curr = _begin + _n + 1;
        --curr;
    }

public:
    explicit circular_buffer(size_t n = 1, const alloc_type& al = alloc_type(), size_t capacity = 1) : _n(n), _alloc(al), _capacity(capacity)
    {
        _buff = alloc_traits::allocate(_alloc, n + 1);
        _head = _buff;
        _end = _buff;
        _begin = _buff;
    }

    ~circular_buffer()
    {
        alloc_traits::deallocate(_alloc, _buff, _n + 1);
    }

    circular_buffer& operator=(const circular_buffer& b)
    {
        if (*this == b)
            return *this;
        this->_buffer = b._buffer;
        this->_n = b._n;
        this->_capacity = b._capacity;
        this->_head = b._head;
        this->_end = b._end;
        this->_begin = b._begin;
        return *this;
    }

    T& operator[](const int& n) const
    {
        if (_begin + _n + 1 <= _head + n)
        {
            throw std::invalid_argument("Element missing");
        }
        else
        {
            return *(_head + n);
        }
    }

    ra_iterator<T> begin() { return ra_iterator(_head, _begin, _begin + _n, _head); }

    ra_iterator<T> end() { return ra_iterator(_end, _begin, _begin + _n, _head); }

    T& front() const { return *_head; }

    T& back() const
    {
        if (_end == _begin)
        {
            if (_head == _begin)
                return *_end;
            return *(_begin + _n);
        }
        return *(_end - 1);
    }

    ra_iterator<const T> begin() const { return ra_iterator(_head, _begin, _begin + _n, _head); }

    ra_iterator<const T> end() const { return ra_iterator(_end, _begin, _begin + _n, _head); }

    const T& const_front() const { return _head; }

    const T& const_back() const
    {
        if (_end == _begin)
        {
            if (_head == _begin)
                return *_end;
            return *(_begin + _n);
        }
        return *(_end - 1);
    }

    void resize(size_t n)
    {
        _capacity = _n;
        T* buffer = alloc_traits::allocate(_alloc, n + 1);
        int i = 0;
        T* head = _head;
        while (_head != _end && i < n)
        {
            alloc_traits::construct(_alloc, (buffer + i), *_head);
            plusplus(_head);
            ++i;
        }
        while (head != _end)
        {
            alloc_traits::destroy(_alloc, (head));
            plusplus(head);
        }
        alloc_traits::deallocate(_alloc, _buff, _n + 1);
        _buff = buffer;
        _n = n;
        _head = _buff;
        _end = _buff + i;
    }

    void push_front(const T& val)
    {
        minusminus(_head);
        alloc_traits::construct(_alloc, _head, val);
        if (_head == _end)
        {
            _capacity++;
            _n++;
            minusminus(_end);
        }
    }

    void pop_front()
    {
        if (_head == _end)
            throw std::invalid_argument("Element missing");
        alloc_traits::destroy(_alloc, _head);
        plusplus(_head);
        resize(_n - 1);
        _capacity = _n;
    }

    void push_back(const T& val)
    {
        alloc_traits::construct(_alloc, _end, val);
        plusplus(_end);
        if (_end == _head)
        {
            _capacity++;
            _n++;
            minusminus(_end);
        }
    }

    void pop_back()
    {
        if (_head == _end)
            throw std::invalid_argument("Element missing");
        minusminus(_end);
        alloc_traits::destroy(_alloc, _end);
        resize(_n - 1);
        _capacity = _n;
    }

    size_t size() const
    {
        return _n;
    }

    size_t capacity() const
    {
        return _capacity;
    }

    void out()
    {
        std::cout << '\n';
        for (auto iter = _head; iter != _end; plusplus(iter))
            std::cout << *iter << " ";
        std::cout << '\n';
        std::cout << "Value of first element: " << *_head << "\n";
        std::cout << "Value of last element: " << back() << "\n";
    }
};

#endif
