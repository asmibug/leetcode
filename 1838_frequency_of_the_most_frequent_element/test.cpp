#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    EXPECT_EQ(3, func({1,2,4}, 5)); \
} \
UTEST(func, 2) { \
    EXPECT_EQ(2, func({1,4,8,13}, 5)); \
} \
UTEST(func, 3) { \
    EXPECT_EQ(1, func({3,9,6}, 2)); \
} \

INSERT_TESTS(GetMaxWindowSort)
INSERT_TESTS(GetMaxWindowCount)
