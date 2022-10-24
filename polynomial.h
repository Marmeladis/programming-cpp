#pragma once
#ifndef POLYNOMINALVECTOR_H
#define POLYNOMINALVECTOR_H

#include <iostream>
#include <array>
#include <cmath>

class PolynomialVector
{
private:
    std::array<int, 3> odds = { 1, 2, 3 };

public:
    template<typename T>
    constexpr int Solve(const T x) const
    {
        int size = odds.size();

        int answer = 0;

        for (int i = 0; i < size; i++)
        {
            int tmp = 1;

            for (int j = i; j < size - 1; j++)
            {
                tmp *= x;
            }

            answer += odds[i] * tmp;
        }

        return answer;
    }

    double operator[](int index) const
    {
        int size = odds.size();

        if (index >= size)
            throw std::invalid_argument("incorrect index!");

        return odds[index];
    }

    PolynomialVector& operator=(const PolynomialVector& other) = default;


    friend std::ostream& operator<<(std::ostream& out, const PolynomialVector& polynomial)
    {
        int size = polynomial.odds.size();

        for (int i = 0; i < size; i++)
        {
            double thisOdd = polynomial.odds[i];

            if (thisOdd == 0)
                continue;

            if (i == size - 1)
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
                    out << thisOdd << "x^" << size - i - 1;
                else
                    out << " -" << abs(thisOdd) << "x^" << size - i - 1;
            }
            else
            {
                if (thisOdd > 0)
                    out << " + " << thisOdd << "x^" << size - i - 1;
                else
                    out << " - " << abs(thisOdd) << "x^" << size - i - 1;
            }
        }

        return out;
    }

};
#endif