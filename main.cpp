#include <vector>
#include "algorithms_stl.h"

// простое
bool isPrime(int number)
{
    number = abs(number);

    if (number == 0 || number == 1)
    {
        return false;
    }
    int divisor;
    for (divisor = number / 2; number % divisor != 0; --divisor)
    {
        ;
    }
    return divisor == 1;
}

// нечетность
bool odd(int a)
{
    return a % 2;
}

// по возрастанию
bool comparator(int a, int b)
{
    return a <= b;
}

int main()
{
    std::vector<int> gg = {};
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;
        gg.push_back(x);
    }


}