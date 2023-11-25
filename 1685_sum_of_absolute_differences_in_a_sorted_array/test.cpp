#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define ASSERT_VECT(expected, result) do { \
    auto _expected = expected; \
    auto _result = result; \
    ASSERT_EQ(_expected.size(), _result.size()); \
    for (unsigned i = 0; i < _expected.size(); ++i) { \
        EXPECT_EQ(_expected[i], _result[i]); \
    } \
} while (0) \

UTEST(GetDifferencesSum, 1) {
    ASSERT_VECT((std::vector{4,3,5}), GetDifferencesSum({2,3,5}));
}

UTEST(GetDifferencesSum, 2) {
    ASSERT_VECT((std::vector{24,15,13,15,21}), GetDifferencesSum({1,4,6,8,10}));
}
