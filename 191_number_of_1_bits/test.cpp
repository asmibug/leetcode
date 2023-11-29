#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    EXPECT_EQ(3, func(11)); \
    EXPECT_EQ(1, func(1 << 8)); \
    EXPECT_EQ(31, func(-3)); \
} \

INSERT_TESTS(CountOneBitsIteratively)
INSERT_TESTS(CountOneBitsBrianKernighan)
INSERT_TESTS(CountOneBitsBitset)
