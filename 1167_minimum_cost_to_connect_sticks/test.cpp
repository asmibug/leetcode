#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    EXPECT_EQ(14, func({2,4,3})); \
    EXPECT_EQ(30, func({1,8,3,5})); \
    EXPECT_EQ(0, func({5})); \
} \

INSERT_TESTS(GetMinMergeTimeHeap)
INSERT_TESTS(GetMinMergeTimeSort)
INSERT_TESTS(GetMinMergeTimeSortOptimized)
