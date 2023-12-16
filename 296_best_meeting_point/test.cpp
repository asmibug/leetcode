#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    EXPECT_EQ(6, func({{1,0,0,0,1},{0,0,0,0,0},{0,0,1,0,0}})); \
    EXPECT_EQ(1, func({{1,1}})); \
} \

INSERT_TESTS(GetMinTotalDistByCountAndSumForward)
INSERT_TESTS(GetMinTotalDistByCountAndTwoPointers)
