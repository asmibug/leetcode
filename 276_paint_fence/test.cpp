#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    EXPECT_EQ(6, func(3, 2)); \
    EXPECT_EQ(1, func(1, 1)); \
    EXPECT_EQ(42, func(7, 2)); \
} \

INSERT_TESTS(GetNumWaysRecursiveLambda1)
INSERT_TESTS(GetNumWaysRecursiveLambda2)
INSERT_TESTS(GetNumWaysIterative)
