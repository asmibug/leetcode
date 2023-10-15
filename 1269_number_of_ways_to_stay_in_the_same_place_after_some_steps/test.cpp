#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetNumWaysRecursion, 1) {
    EXPECT_EQ(4, GetNumWaysRecursion(3, 2));
}

UTEST(GetNumWaysRecursion, 2) {
    EXPECT_EQ(2, GetNumWaysRecursion(2, 4));
}

UTEST(GetNumWaysRecursion, 3) {
    EXPECT_EQ(8, GetNumWaysRecursion(4, 2));
}


UTEST(GetNumWaysIteration, 1) {
    EXPECT_EQ(4, GetNumWaysIteration(3, 2));
}

UTEST(GetNumWaysIteration, 2) {
    EXPECT_EQ(2, GetNumWaysIteration(2, 4));
}

UTEST(GetNumWaysIteration, 3) {
    EXPECT_EQ(8, GetNumWaysIteration(4, 2));
}
