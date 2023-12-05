#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    EXPECT_EQ(58, func({34,23,1,24,75,33,54,8}, 60)); \
    EXPECT_EQ(-1, func({10,20,30}, 15)); \
} \

INSERT_TESTS(GetMaxSumByMap)
INSERT_TESTS(GetMaxSumBySortBinSearch)
INSERT_TESTS(GetMaxSumBySortTwoPointers)
INSERT_TESTS(GetMaxSumByCounting)
INSERT_TESTS(GetMaxSumByBucket)
