#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    EXPECT_EQ(7, func({3,5,2,3})); \
} \
UTEST(func, 2) { \
    EXPECT_EQ(8, func({3,5,4,2,4,6})); \
} \

INSERT_TESTS(GetMinPairSumSort)
INSERT_TESTS(GetMinPairSumCount)
