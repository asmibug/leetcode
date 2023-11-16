#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    EXPECT_EQ(2, func({2,2,1,2,1})); \
} \
UTEST(func, 2) { \
    EXPECT_EQ(3, func({100,1,1000})); \
} \
UTEST(func, 3) { \
    EXPECT_EQ(5, func({1,2,3,4,5})); \
} \

INSERT_TESTS(GetMaxStepsSort)
INSERT_TESTS(GetMaxStepsCount)
