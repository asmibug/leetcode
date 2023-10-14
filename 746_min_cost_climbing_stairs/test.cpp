#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetMinTotalCost, 1) {
    EXPECT_EQ(15, GetMinTotalCost({10,15,20}));
}

UTEST(GetMinTotalCost, 2) {
    EXPECT_EQ(6, GetMinTotalCost({1,100,1,1,1,100,1,1,100,1}));
}
