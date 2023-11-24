#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    EXPECT_EQ(9, func({2,4,1,2,7,8})); \
} \
UTEST(func, 2) { \
    EXPECT_EQ(4, func({2,4,5})); \
} \
UTEST(func, 3) { \
    EXPECT_EQ(18, func({9,8,7,6,5,1,2,3,4})); \
} \

INSERT_TESTS(GetMaxCoinsSort)
INSERT_TESTS(GetMaxCoinsCount)
