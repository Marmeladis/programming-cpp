#include "pch.h"
#include "polynomial.h"
TEST(Test, AnswerForTest)
{
    constexpr PolynomialVector<1, 2, 3, 4> polynomial;

    static_assert(polynomial.Solve(1) == 10, "error");

    EXPECT_EQ(6, polynomial.Solve(1));
}
int main(int argc, char* argv[])
{
    int const static odd = 2;

    constexpr PolynomialVector<1, 2, 3> polynomial;
    int value = polynomial.Solve(odd);

    testing::InitGoogleTest(&argc, argv);

    std::cout << polynomial;

    return RUN_ALL_TESTS();
}
