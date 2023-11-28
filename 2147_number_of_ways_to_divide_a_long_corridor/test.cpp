#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    EXPECT_EQ(3, func("SSPPSPS")); \
} \
UTEST(func, 2) { \
    EXPECT_EQ(1, func("PPSPSP")); \
} \
UTEST(func, 3) { \
    EXPECT_EQ(0, func("S")); \
} \

INSERT_TESTS(GetNumberOfWaysByMultiplication)
INSERT_TESTS(GetNumberOfWaysByDP)
