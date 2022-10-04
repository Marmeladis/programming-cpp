#pragma once
#ifndef POLYNOMINALVECTOR_H
#define POLYNOMINALVECTOR_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>

class PolynomialVector
{
private:
    std::vector<double> odds = {};

public:
    template <typename T>
    constexpr double Solve(const T x)
    {
        if (x == 0)
        {
            if (odds.size() > 0)
                return odds[0];
            else
                throw std::invalid_argument("Your polinom is empty");
        }
        else
        {
            double answer = 0;
            for (int i = 0; i < odds.size(); i++)
            {
                answer += odds[i] * std::pow(x, i);
            }
            return answer;
        }
    }

    std::size_t Size() const
    {
        return odds.size();
    }

    const std::vector<double>& GetOdds() const
    {
        return odds;
    }

    PolynomialVector(const std::vector<double>& e)
    {
        odds.resize(e.size());
        for (int i = 0; i < odds.size(); i++)
        {
            odds[i] = e[i];
        }
    }

    explicit PolynomialVector(std::size_t n = 0)
    {
        odds.resize(n + 1, 0.0);
    }

    PolynomialVector(const PolynomialVector& other) : odds(other.odds)
    {
    }

    double& operator[](int index)
    {
        if (index >= this->Size())
            throw std::invalid_argument("incorrect index!");
        return this->odds[index % odds.size()];
    }

    double operator[](int index) const
    {
        if (index >= this->Size())
            throw std::invalid_argument("incorrect index!");
        return this->odds[index % odds.size()];
    }

    PolynomialVector& operator=(const PolynomialVector& other)
    {
        if (this == &other)
            return *this;
        odds.assign(other.odds.begin(), other.odds.end());
        return *this;
    }

    bool operator==(const PolynomialVector& other) const
    {
        return *this == other;
    }

    bool operator!=(const PolynomialVector& other) const
    {
        return !(*this == other);
    }

    PolynomialVector operator+(const PolynomialVector& other) const
    {
        PolynomialVector res(*this);
        res += other;
        return res;
    }

    PolynomialVector operator-() const
    {
        PolynomialVector res(Size());
        for (int i = 0; i < Size() + 1; i++)
        {
            res.odds[i] = -odds[i];
        }
        return res;
    }

    PolynomialVector operator-(PolynomialVector& other) const
    {
        return ((-other) + (*this));
    }

    PolynomialVector& operator+=(const PolynomialVector& other)
    {
        if (Size() < other.Size())
        {
            odds.resize(other.Size() + 1);
        }
        for (int i = 0; i < Size() + 1; i++)
        {
            odds[i] += other.odds[i];
        }
        return (*this);
    }

    PolynomialVector& operator-=(const PolynomialVector& other)
    {
        if (Size() < other.Size())
        {
            odds.resize(other.Size() + 1);
        }
        for (int i = 0; i < Size() + 1; i++)
        {
            odds[i] -= other.odds[i];
        }
        return (*this);
    }

    PolynomialVector operator*(PolynomialVector& other) const
    {
        PolynomialVector res(*this);
        res *= other;
        return res;
    }

    PolynomialVector operator/(double value)
    {
        PolynomialVector res(Size() + 1);
        for (int i = 0; i < Size() + 1; i++)
            res.odds[i] = odds[i] / value;
        return res;
    }

    PolynomialVector& operator*=(PolynomialVector& other)
    {
        std::vector<double> new_odds(other.Size() + Size() + 1);
        for (int i = 0; i < Size() + 1; i++)
        {
            for (int j = 0; j < other.Size() + 1; j++)
            {
                new_odds[i + j] += odds[i] * other.odds[j];
            }
        }
        odds = new_odds;
        return *this;
    }

    PolynomialVector& operator/=(double value)
    {
        for (int i = 0; i < Size() + 1; i++)
            odds[i] /= value;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const PolynomialVector& polynomial);

    friend std::istream& operator>>(std::istream& in, PolynomialVector& polynomial);

    void integrate(int constanta)
    {
        odds.resize(odds.size() + 1);
        for (std::size_t i = odds.size() - 1; i > 0; --i)
        {
            odds[i] = odds[i - 1] / i;
        }
        odds[0] = constanta;
    }

    void differentiate()
    {
        for (int i = 0; i < odds.size() - 1; i++)
        {
            odds[i] = odds[i + 1] * (i + 1);
        }
        odds.pop_back();
    }

    ~PolynomialVector() = default;
};

std::ostream& operator<<(std::ostream& out, const PolynomialVector& polynomial)
{
    for (int i = polynomial.Size(); i >= 0; i--)
    {
        double thisOdd = polynomial.odds[i];
        if (i == 0)
            out << thisOdd;
        else
        {
            if (thisOdd == 0)
                continue;
            if (thisOdd > 0)
            {
                out << std::setprecision(2) << thisOdd << "x^" << i << "+";
            }
            else if (thisOdd < 0)
            {
                out << std::setprecision(2) << "(" << thisOdd << ")"
                    << "x^" << i << "+";
            }
        }
    }
    return out;
}

std::istream& operator>>(std::istream& in, PolynomialVector& polynomial)
{
    std::size_t n;
    in >> n;
    polynomial.odds.resize(n + 1);
    for (int i = 0; i < polynomial.odds.size(); i++)
    {
        in >> polynomial.odds[i];
    }
    return in;
}

#endif
