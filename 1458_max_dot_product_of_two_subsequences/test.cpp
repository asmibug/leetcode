#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetMaxDotProduct, 1) {
    EXPECT_EQ(18, GetMaxDotProduct({2,1,-2,5}, {3,0,-6}));
}

UTEST(GetMaxDotProduct, 2) {
    EXPECT_EQ(21, GetMaxDotProduct({3,-2}, {2,-6,7}));
}

UTEST(GetMaxDotProduct, 3) {
    EXPECT_EQ(-1, GetMaxDotProduct({-1,-1}, {1,1}));
}
