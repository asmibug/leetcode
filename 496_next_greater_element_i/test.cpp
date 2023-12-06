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

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    ASSERT_VECT((std::vector{-1,3,-1}), func({4,1,2}, {1,3,4,2})); \
    ASSERT_VECT((std::vector{3,-1}), func({2,4}, {1,2,3,4})); \
} \

INSERT_TESTS(GetGreaterElementsIndicesByStack)
INSERT_TESTS(GetGreaterElementsIndicesByMap)
