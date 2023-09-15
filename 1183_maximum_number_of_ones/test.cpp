#include "lib.cpp"

#include "utest.h"

UTEST(GetMaxNumberOfOnes, 3_3_2_1) {
    EXPECT_EQ(4, GetMaxNumberOfOnes(3, 3, 2, 1));
}

UTEST(GetMaxNumberOfOnes, 3_3_2_2) {
    EXPECT_EQ(6, GetMaxNumberOfOnes(3, 3, 2, 2));
}

UTEST_MAIN()
