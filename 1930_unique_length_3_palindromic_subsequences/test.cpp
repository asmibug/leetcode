#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    EXPECT_EQ(3, func("aabca")); \
} \
UTEST(func, 2) { \
    EXPECT_EQ(0, func("adc")); \
} \
UTEST(func, 4) { \
    EXPECT_EQ(4, func("bbcbaba")); \
} \

INSERT_TESTS(CountPalindromicSubsequenceSet)
INSERT_TESTS(CountPalindromicSubsequenceBinSearch)
