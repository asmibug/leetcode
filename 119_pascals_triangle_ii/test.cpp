#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define ASSERT_VECT(expected, result) do { \
    auto&& _expected = expected; \
    auto&& _result = result; \
    ASSERT_EQ(_expected.size(), _result.size()); \
    for (auto i = 0u; i < expected.size(); ++i) { \
        EXPECT_EQ(_expected[i], _result[i]); \
    } \
} while (0) \

UTEST(GetRowIteration, 0) {
    ASSERT_VECT(std::vector{1}, GetRowIteration(0));
}

UTEST(GetRowIteration, 1) {
    ASSERT_VECT((std::vector{1,1}), GetRowIteration(1));
}

UTEST(GetRowIteration, 2) {
    ASSERT_VECT((std::vector{1,2,1}), GetRowIteration(2));
}

UTEST(GetRowIteration, 3) {
    ASSERT_VECT((std::vector{1,3,3,1}), GetRowIteration(3));
}


UTEST(GetRowMath, 0) {
    ASSERT_VECT(std::vector{1}, GetRowMath(0));
}

UTEST(GetRowMath, 1) {
    ASSERT_VECT((std::vector{1,1}), GetRowMath(1));
}

UTEST(GetRowMath, 2) {
    ASSERT_VECT((std::vector{1,2,1}), GetRowMath(2));
}

UTEST(GetRowMath, 3) {
    ASSERT_VECT((std::vector{1,3,3,1}), GetRowMath(3));
}