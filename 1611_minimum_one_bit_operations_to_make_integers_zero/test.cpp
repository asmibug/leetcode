#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    EXPECT_EQ(2, func(3)); \
    EXPECT_EQ(4, func(6)); \
    EXPECT_EQ(14, func(9)); \
} \

INSERT_TESTS(GetMinOperationsApproach1Recursive)
INSERT_TESTS(GetMinOperationsApproach2Iterative)
INSERT_TESTS(GetMinOperationsApproach3Iterative)
INSERT_TESTS(GetMinOperationsReverseGray)
INSERT_TESTS(GetMinOperationsDP)
