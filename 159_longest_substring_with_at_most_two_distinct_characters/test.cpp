#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    EXPECT_EQ(3, func("eceba")); \
    EXPECT_EQ(5, func("ccaabbb")); \
    EXPECT_EQ(4, func("abaccc")); \
    EXPECT_EQ(13, func("aabbaaabbbaaa")); \
} \

INSERT_TESTS(GetLenOfLongestSubstrShrinkableLastChange)
INSERT_TESTS(GetLenOfLongestSubstrShrinkableCountStreak)
INSERT_TESTS(GetLenOfLongestSubstrShrinkableIndices)
INSERT_TESTS(GetLenOfLongestSubstrShrinkableLastIndex)
INSERT_TESTS(GetLenOfLongestSubstrShrinkableCounts)
INSERT_TESTS(GetLenOfLongestSubstrMonotonous)
