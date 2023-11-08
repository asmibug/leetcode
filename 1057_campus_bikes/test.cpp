#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    std::vector<int> result = func({{0,0},{2,1}}, {{1,2},{3,3}}); \
    ASSERT_EQ(2u, result.size()); \
    EXPECT_EQ(1, result[0]); \
    EXPECT_EQ(0, result[1]); \
} \
UTEST(func, 2) { \
    auto result = func({{0,0},{1,1},{2,0}}, {{1,0},{2,2},{2,1}}); \
    ASSERT_EQ(3u, result.size()); \
    EXPECT_EQ(0, result[0]); \
    EXPECT_EQ(2, result[1]); \
    EXPECT_EQ(1, result[2]); \
} \

INSERT_TESTS(AssignBikesSortLambda)
INSERT_TESTS(AssignBikesSortComparator)
INSERT_TESTS(AssignBikesSortPrecompute)
INSERT_TESTS(AssignBikesSortBucket)
INSERT_TESTS(AssignBikesByWorkerHeap)
INSERT_TESTS(AssignBikesByWorkerHeapSimpler)
INSERT_TESTS(AssignBikesByWorkerGaleShapley)
INSERT_TESTS(AssignBikesByWorkerGraph)
INSERT_TESTS(AssignBikesByWorkerGraphSimple)
INSERT_TESTS(AssignBikesByWorkerGraphOptimized)
