

#ifndef LAB3_ALGO_H
#define LAB3_ALGO_H

template<class InputIterator, class Predicate>
bool all_of(InputIterator first, InputIterator last, Predicate predicate)
{
    while (first != last)
    {
        if (!predicate(*first)) return false;

        first = first + 1;
    }

    return true;
}

template<class InputIterator, class Predicate>
bool any_of(InputIterator first, InputIterator last, Predicate predicate)
{
    while (first != last)
    {
        if (predicate(*first)) return true;

        first++;
    }

    return false;
}

template<class InputIterator, class Predicate>
bool none_of(InputIterator first, InputIterator last, Predicate predicate)
{
    while (first != last)
    {
        if (predicate(*first)) return false;

        first++;
    }

    return true;
}

template<class InputIterator, class Predicate>
size_t count_if(InputIterator first, InputIterator last, Predicate predicate)
{
    size_t count = 0;

    while (first != last)
    {
        if (*first == predicate) count++;

        first++;
    }

    return count;
}

template<class InputIterator, class Predicate>
bool one_of(InputIterator first, InputIterator last, Predicate predicate)
{
    int count = count_if(first, last, predicate);

    if (count == 1) return true;

    return false;
}

template<class InputIterator, class CompareFunc>
bool is_sorted(InputIterator first, InputIterator last, CompareFunc compare = std::less<>())
{
    if (first == last) return true;

    InputIterator next = first;

    while (++next != last)
    {
        if (compare(*next, *first)) return false;

        first++;
    }

    return true;
}

template<class InputIterator, class Predicate>
bool is_partitioned(InputIterator first, InputIterator last, Predicate predicate)
{
    for (; first != last; first++)
    {
        if (!p(*first)) break;
    }
    for (; first != last; first++)
    {
        if (p(*first)) return false;
    }
    return true;
}

template<class InputIterator, class Value>
InputIterator find_not(InputIterator first, InputIterator last, Value value)
{
    while (first != last)
    {
        if (*first != value) return first;

        first++;
    }

    return -1;
}

template<class InputIterator, class Value>
InputIterator find_backward(InputIterator first, InputIterator last, Value value)
{
    InputIterator it = -1;
    while (first != last)
    {
        if (*first == value) it = first;

        first++;
    }

    return -it;
}

template<class InputIterator, class Predicate>
bool is_palindrome(InputIterator first, InputIterator last, Predicate predicate)
{
    while (first < last)
    {
        if (!predicate(*first, *last)) return false;

        first++;
        last--;
    }

    return true;
}

#endif //LAB3_ALGO_H