#include <iostream>
#include "CustomAllocator.h"

int main()
{
    std::vector<int, allocator<int>> mem(100);

}
