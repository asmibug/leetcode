#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(CalculateTime, 1) {
    EXPECT_EQ(4, CalculateTime("abcdefghijklmnopqrstuvwxyz", "cba"));
    EXPECT_EQ(73, CalculateTime("pqrstuvwxyzabcdefghijklmno", "leetcode"));
}
