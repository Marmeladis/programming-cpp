#pragma once
#ifndef POLYNOMINALVECTOR_H
#define POLYNOMINALVECTOR_H

#include <iostream>
#include <array>
#include <cmath>

template<int ...T>
class PolynomialVector
{
private:
    int odds[sizeof...(T)] = { T... };

public:

    constexpr int Solve(const int x) const
    {
        int answer = 0;

        for (int i = 0; i < sizeof...(T); i++)
        {
            int tmp = 1;

            for (int j = i; j < sizeof...(T) - 1; j++)
            {
                tmp *= x;
            }

            answer += odds[i] * tmp;
        }

        return answer;
    }

    constexpr int operator[](std::size_t index) const
    {
        return odds[index];
    }

    PolynomialVector& operator=(const PolynomialVector& other) = default;


    friend std::ostream& operator<<(std::ostream& out, const PolynomialVector& polynomial)
    {
        for (int i = 0; i < sizeof...(T); i++)
        {
            double thisOdd = polynomial.odds[i];

            if (thisOdd == 0)
                continue;

            if (i == sizeof...(T) - 1)
            {
                if (thisOdd < 0)
                    out << " - ";
                else
                    out << " + ";

                out << thisOdd;
            }
            else if (i == 0)
            {
                if (thisOdd > 0)
                    out << thisOdd << "x^" << sizeof...(T) - i - 1;
                else
                    out << " -" << abs(thisOdd) << "x^" << sizeof...(T) - i - 1;
            }
            else
            {
                if (thisOdd > 0)
                    out << " + " << thisOdd << "x^" << sizeof...(T) - i - 1;
                else
                    out << " - " << abs(thisOdd) << "x^" << sizeof...(T) - i - 1;
            }
        }

        return out;
    }

};
#endif
