#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()


UTEST(IsPowerOf4C20, 1) {
    EXPECT_TRUE(IsPowerOf4C20(16));
}

UTEST(IsPowerOf4C20, 2) {
    EXPECT_FALSE(IsPowerOf4C20(5));
}

UTEST(IsPowerOf4C20, 3) {
    EXPECT_TRUE(IsPowerOf4C20(1));
}

UTEST(IsPowerOf4C20, 4) {
    EXPECT_FALSE(IsPowerOf4C20(8));
}


UTEST(IsPowerOf4Log, 1) {
    EXPECT_TRUE(IsPowerOf4Log(16));
}

UTEST(IsPowerOf4Log, 2) {
    EXPECT_FALSE(IsPowerOf4Log(5));
}

UTEST(IsPowerOf4Log, 3) {
    EXPECT_TRUE(IsPowerOf4Log(1));
}

UTEST(IsPowerOf4Log, 4) {
    EXPECT_FALSE(IsPowerOf4Log(8));
}


UTEST(IsPowerOf4Math, 1) {
    EXPECT_TRUE(IsPowerOf4Math(16));
}

UTEST(IsPowerOf4Math, 2) {
    EXPECT_FALSE(IsPowerOf4Math(5));
}

UTEST(IsPowerOf4Math, 3) {
    EXPECT_TRUE(IsPowerOf4Math(1));
}

UTEST(IsPowerOf4Math, 4) {
    EXPECT_FALSE(IsPowerOf4Math(8));
}


UTEST(IsPowerOf4Mask, 1) {
    EXPECT_TRUE(IsPowerOf4Mask(16));
}

UTEST(IsPowerOf4Mask, 2) {
    EXPECT_FALSE(IsPowerOf4Mask(5));
}

UTEST(IsPowerOf4Mask, 3) {
    EXPECT_TRUE(IsPowerOf4Mask(1));
}

UTEST(IsPowerOf4Mask, 4) {
    EXPECT_FALSE(IsPowerOf4Mask(8));
}
