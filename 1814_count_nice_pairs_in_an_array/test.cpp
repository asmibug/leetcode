#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    EXPECT_EQ(2, func({42,11,1,97})); \
} \
UTEST(func, 2) { \
    EXPECT_EQ(4, func({13,10,35,24,76})); \
} \

INSERT_TESTS(CountNicePairsHash)
