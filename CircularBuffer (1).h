#ifndef LAB3_CIRCULARBUFFER_H
#define LAB3_CIRCULARBUFFER_H

#include <exception>

template<typename CircularBuffer>
class Iterator
{
public:
    using iterator_category = std::random_access_iterator_tag;
    using value_type = typename CircularBuffer::value_type;
    using difference_type = ptrdiff_t;
    using pointer = value_type*;
    using reference = value_type&;

    explicit Iterator(pointer ptr) : _ptr(ptr)
    {}

    Iterator(const Iterator& other) : _ptr(other._ptr)
    {}

    ~Iterator() = default;

    /*Iterator& operator=(const Iterator& other)
    {

    }*/

    bool operator==(const Iterator& other) const
    { return _ptr == other._ptr; }

    bool operator!=(const Iterator& other) const
    { return !(*this == other); }

    bool operator>(const Iterator& other) const
    { return _ptr > other._ptr; }

    bool operator<(const Iterator& other) const
    { return _ptr < other._ptr; }

    Iterator operator+(difference_type value)
    {
        Iterator tempValue = *this;
        tempValue += value;

        return tempValue;
    }

    Iterator& operator+=(difference_type value)
    {
        _ptr += value;
        return *this;
    }

    Iterator& operator++()
    {
        _ptr++;
        return *this;
    }

    Iterator operator-(difference_type value)
    {
        Iterator tempValue = *this;
        tempValue -= value;

        return tempValue;
    }

    Iterator& operator-=(difference_type value)
    {
        _ptr -= value;
        return *this;
    }

    Iterator& operator--()
    {
        _ptr--;
        return *this;
    }

    pointer operator->() const
    { return _ptr; }

    reference operator*() const
    { return *_ptr; }

    difference_type operator-(const Iterator& other) const
    { return _ptr - other._ptr; }

private:
    //value_type _data;
    pointer _ptr;
};

template<typename T>
class CircularBuffer
{
private:
    size_t _size;
    size_t _capacity;
    size_t _start;
    size_t _end;
    T* _data;

public:
    using value_type = T;
    using Iterator = Iterator<CircularBuffer<T>>;

    size_t size()
    {
        return _capacity;
    }

    explicit CircularBuffer(size_t capacity = 0) : _size(0), _capacity(capacity), _start(0), _end(0),
                                                   _data(new T[capacity])
    {
        for (auto i = 0; i < _size; i++) _data[i] = 0;
    }

    CircularBuffer(const CircularBuffer& other) : _capacity(other._capacity), _size(other._size), _start(other._start),
                                                  _end(other._end), _data(new T[other._capacity])
    {
        for (auto i = 0; i < _size; i++)
        {
            _data[i] = other._data[i];
        }
    }

    ~CircularBuffer()
    {
        delete[] _data;
    }

    CircularBuffer& operator=(const CircularBuffer& other)
    {
        if (this != &other)
        {
            value_type* data = new value_type[other._capacity];
            std::copy(other.begin(), other.end(), data);
            delete[] _data;

            _data = data;
            _size = other._size;
            _capacity = other._capacity;
            _start = other._start;
            _end = other._end;
        }

        return *this;
    }

    T& operator[](size_t index) const
    {
        if (_size <= 0)
        {
            throw std::out_of_range("CircularBuffer out of range\n");
        }

        return _data[(_start + index) % _capacity];
    }

    void push_back(T value) //
    {
        _end = (++_end) % _capacity;

        _data[_end] = value;

        if (_size != _capacity) _size++;
    }

    void pop_back()
    {
        if (_size > 0)
        {
            _size--;

            _end = (_capacity + _end - 1) % _capacity;
        }
    }

    void push_front(T value)
    {
        _start = (_capacity + _start - 1) % _capacity;
        _data[_start] = value;

        if (_size != _capacity) _size++;
    }

    void pop_front()
    {
        if (_size > 0)
        {
            _size--;

            _end = (_start + 1) % _capacity;
        }
    }

    T first() const
    {
        return _data[_start];
    }

    T last() const
    {
        return _data[_end];
    }

    void reserve(size_t newCapacity)
    {
        if (newCapacity < _size)
        {
            throw std::range_error("New capacity is less than size");
        }

        value_type* data = new value_type[newCapacity];

        for (size_t i = 0; i < _size; i++)
        {
            data[i] = _data[i];
        }

        delete[] _data;

        _data = data;
        _capacity = newCapacity;
        _start = _start % _capacity;
        _end = _end % _capacity;
    }

    Iterator begin()
    {
        return Iterator(_data);
    }

    Iterator end()
    {
        return Iterator(_data + _size);
    }
};


#endif //LAB3_CIRCULARBUFFER_H