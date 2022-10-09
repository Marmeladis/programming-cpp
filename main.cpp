#include "alloc.h"
#include "my_allocator.h"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

struct Object
{
    uint64_t data[2];

    static my_alloc<char> allocator;

    static void* operator new(size_t size)
    {
        return allocator.allocate(size);
    }

    static void operator delete(void* ptr, size_t size)
    {

        return allocator.deallocate(reinterpret_cast<char*>(ptr), size);
    }
};

int main()
{
    constexpr int arraySize = 10;

    Object* objects[arraySize];

    // Two `uint64_t`, 16 bytes.
    cout << "size(Object) = " << sizeof(Object) << endl
        << endl;

    // Allocate 10 objects. This causes allocating two larger,
    // blocks since we store only 8 chunks per block:

    cout << "About to allocate " << arraySize << " objects" << endl;

    for (int i = 0; i < arraySize; ++i)
    {
        objects[i] = new Object();
        cout << "new [" << i << "] = " << objects[i] << endl;
    }

    cout << endl;

    // Deallocated all the objects:

    for (int i = arraySize; i >= 0; --i)
    {
        cout << "delete [" << i << "] = " << objects[i] << endl;
        delete objects[i];
    }

    cout << endl;

    // New object reuses previous block:

    objects[0] = new Object();
    cout << "new [0] = " << objects[0] << endl
        << endl;
}