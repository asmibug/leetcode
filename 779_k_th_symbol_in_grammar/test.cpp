#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetKthOfNIterative, 1) {
    EXPECT_EQ(0, GetKthOfNIterative(1, 1));
}

UTEST(GetKthOfNIterative, 2) {
    EXPECT_EQ(0, GetKthOfNIterative(2, 1));
}

UTEST(GetKthOfNIterative, 3) {
    EXPECT_EQ(1, GetKthOfNIterative(2, 2));
}


UTEST(GetKthOfNMath, 1) {
    EXPECT_EQ(0, GetKthOfNMath(1, 1));
}

UTEST(GetKthOfNMath, 2) {
    EXPECT_EQ(0, GetKthOfNMath(2, 1));
}

UTEST(GetKthOfNMath, 3) {
    EXPECT_EQ(1, GetKthOfNMath(2, 2));
}
