#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    EXPECT_TRUE(func({"ab", "c"}, {"a", "bc"})); \
    EXPECT_FALSE(func({"a", "cb"}, {"ab", "c"})); \
    EXPECT_TRUE(func({"abc", "d", "defg"}, {"abcddefg"})); \
} \

INSERT_TESTS(CheckEqualConcatenation)
INSERT_TESTS(CheckEqualTwoPointers)
