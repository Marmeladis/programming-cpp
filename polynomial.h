#ifndef LAB1_POLYNOMIAL_H
#define LAB1_POLYNOMIAL_H
#include <iostream>
#include <utility>
#include <vector>
#include <stdexcept>
#include <cmath>

class Polynomial {
private:
    std::vector<int> coefficients_;

public:
    Polynomial() = default;

    explicit Polynomial(std::vector<int>& other) : coefficients_(other) {}

    Polynomial (const Polynomial& other) : coefficients_(other.coefficients_) {}

    Polynomial& operator=(const Polynomial& other) {
        if (&other == this) {
            return *this;
        }
        coefficients_ = other.coefficients_;
        return *this;
    }

    bool operator==(const Polynomial& rhs) {
        if (&rhs == this) {
            return true;
        }

        if (coefficients_.size() != rhs.coefficients_.size()) {
            return false;
        }

        for (int i = 0; i < this->coefficients_.size(); ++i) {
            if (coefficients_[i] != rhs.coefficients_[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Polynomial& rhs) {
        return !operator==(rhs);
    }

    Polynomial& operator-() {
        for (int i = 0; i < this->coefficients_.size(); ++i) {
            coefficients_[i] *= -1;
        }
        return *this;
    }

    Polynomial operator+(const Polynomial& rhs) const {
        if (this->coefficients_.size() > rhs.coefficients_.size()) {
            Polynomial tmp(*this);
            size_t newSize = coefficients_.size();
            for (int i = 0; i < newSize; ++i) {
                tmp.coefficients_[i] += rhs.coefficients_[i];
            }
            return tmp;
        } else {
            Polynomial tmp(rhs);
            size_t newSize = rhs.coefficients_.size();
            for (int i = 0; i < newSize; ++i) {
                tmp.coefficients_[i] += coefficients_[i];
            }
            return tmp;
        }
    }

    Polynomial operator-(const Polynomial& rhs) const {
        if (this->coefficients_.size() > rhs.coefficients_.size()) {
            Polynomial tmp(*this);
            size_t newSize = coefficients_.size();
            for (int i = 0; i < newSize; ++i) {
                tmp.coefficients_[i] -= rhs.coefficients_[i];
            }
            return tmp;
        } else {
            Polynomial tmp(rhs);
            size_t newSize = rhs.coefficients_.size();
            for (int i = 0; i < newSize; ++i) {
                tmp.coefficients_[i] -= coefficients_[i];
            }
            return tmp;
        }
    }

    Polynomial& operator++() {
        coefficients_[coefficients_.size() - 1] += 1;
        return *this;
    }

    Polynomial operator++(int) {
        Polynomial tmp(*this);
        operator++();
        return tmp;
    }

    Polynomial& operator--() {
        coefficients_[coefficients_.size() - 1] -= 1;
        return *this;
    }

    Polynomial operator--(int) {
        Polynomial tmp(*this);
        operator--();
        return tmp;
    }

    Polynomial& operator+=(const int& number) {
        coefficients_[coefficients_.size() - 1] += number;
        return *this;
    }

    Polynomial& operator-=(const int& number) {
        coefficients_[coefficients_.size() - 1] -= number;
        return *this;
    }

    Polynomial& operator*=(const int& number) {
        for (int i = 0; i < this->coefficients_.size(); ++i) {
            coefficients_[i] *= number;
        }
        return *this;
    }

    Polynomial operator*(const int& number) const {
        Polynomial tmp(*this);
        tmp *= number;
        return tmp;
    }

    Polynomial operator*(const Polynomial& rhs) const {
        Polynomial tmp;
        tmp.coefficients_.resize(coefficients_.size() + rhs.coefficients_.size() - 1);
        for (int i = 0; i < coefficients_.size(); ++i) {
            for (int j = 0; j < rhs.coefficients_.size(); ++j) {
                tmp.coefficients_[i + j] += coefficients_[i] * rhs.coefficients_[j];
            }
        }
        return tmp;
    }

    Polynomial& operator*=(const Polynomial& rhs) {
        *this = operator*(rhs);
        return *this;
    }

    Polynomial& operator/=(const int& number) {
        for (int i = 0; i < this->coefficients_.size(); ++i) {
            coefficients_[i] /= number;
        }
        return *this;
    }

    Polynomial operator/(const int& number) const {
        Polynomial tmp(*this);
        tmp /= number;
        return tmp;
    }

    const int& operator[](const size_t& index) const {
        if (index >= this->coefficients_.size()) {
            throw std::out_of_range("index out of range");
        }
        return this->coefficients_[index];
    }

    friend std::ostream& operator<<(std::ostream& stream, const Polynomial&);

    friend std::istream& operator>>(std::istream& stream, Polynomial&);
};

std::ostream& operator<<(std::ostream& stream, const Polynomial& polynomial) {
    for (int i = 0; i < polynomial.coefficients_.size() - 1; ++i) {
        switch (polynomial.coefficients_[i]) {
            case 0 : {
                break;
            }
            case 1 : {
                (i == 0 || polynomial.coefficients_[i - 1] == 0 ? stream << "x^" : stream << " + x^");
                stream << polynomial.coefficients_.size() - i - 1;
                break;
            }
            case -1 : {
                (i == 0 || polynomial.coefficients_[i - 1] == 0 ? stream << "-x^" : stream << " - x^");
                stream << polynomial.coefficients_.size() - i - 1;
                break;
            }
            default : {
                if (polynomial.coefficients_[i] < 0) {
                    (i == 0 ? stream << "-" : stream << " - ");
                    stream << fabs(polynomial.coefficients_[i]) << "x^" << polynomial.coefficients_.size() - i - 1;
                } else {
                    (i == 0 ? stream << "" : stream << " + ");
                    stream << polynomial.coefficients_[i] << "x^" << polynomial.coefficients_.size() - i - 1;
                }
                break;
            }
        }
    }

    if (polynomial[polynomial.coefficients_.size() - 1] < 0) {
        stream << " - " << fabs(polynomial[polynomial.coefficients_.size() - 1]) << "\n";
    } else {
        stream << " + " << polynomial[polynomial.coefficients_.size() - 1] << "\n";
    }

    return stream;
}

std::istream& operator>>(std::istream& stream, Polynomial& polynomial) {
    polynomial.coefficients_.clear();
    size_t maxDegree;
    stream >> maxDegree;
    for (int i = 0; i <= maxDegree; ++i) {
        int coefficient;
        stream >> coefficient;
        polynomial.coefficients_.emplace_back(coefficient);
    }
    return stream;
}

#endif //LAB1_POLYNOMIAL_H
