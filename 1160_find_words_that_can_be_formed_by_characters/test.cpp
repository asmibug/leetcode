#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    EXPECT_EQ(6, func( \
        {"cat","bt","hat","tree"}, "atach")); \
    EXPECT_EQ(10, func( \
        {"hello","world","leetcode"}, "welldonehoneyr")); \
} \

INSERT_TESTS(GetSumOfValidWordsBySort)
INSERT_TESTS(GetSumOfValidWordsByCount)
