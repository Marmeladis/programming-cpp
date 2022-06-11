#include <iostream>
#include "CircularBuffer.h"
#include "algo.h"
#include <vector>
#include <array>
#include <deque>
#include <iterator>


using namespace std;

int main()
{

   CircularBuffer<int> a(6);

    for (int i = 0; i < 6; i++) a.push_front(i);

    for (auto i : a)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    a.push_front(12);
    a.push_front(12);
    //std::sort(a.begin(), a.end());


    if (all_of(a.begin(), a.end(), [](int i){ return i % 2 == 0; })) {
        std::cout << "All numbers are even\n";
    }


    return 0;
}