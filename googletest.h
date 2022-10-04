#pragma once
#ifndef GOOGLETEST_H
#define GOOGLETEST_H

#include <gtest/gtest.h>
#include "polynomialvector.h"

TEST(Test, AnswerForTest)
{
    PolynomialVector p1({ 0, 0, 0, 0 });
    ASSERT_EQ(0 + 0 + 0 + 0, p1.Solve(0));

    PolynomialVector p1({ 0, 0, 0, 1 });
    ASSERT_EQ(0 + 0 + 0 + 1 * pow(2, 3), p1.Solve(2));

    PolynomialVector p1({ 1, 2, 3 });
    ASSERT_EQ(1 + 2 * pow(0, 1) + 3 * pow(0, 2), p1.Solve(0));

    PolynomialVector p1({ 100, 3, 4, 5 });
    ASSERT_EQ(100 * pow(0, 0) + 3 * pow(2, 1) + 4 * pow(2, 3) + 0, p1.Solve(2));

    PolynomialVector p1(3);
    ASSERT_EQ(0 + 0 + 0 + 0, p1.Solve(1231));

    PolynomialVector p1(0);
    ASSERT_EQ(0, p1.Solve(4));
}

#endif