#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetIdenticalPairsNum, 1) {
    EXPECT_EQ(4, GetIdenticalPairsNum({1,2,3,1,1,3}));
}

UTEST(GetIdenticalPairsNum, 2) {
    EXPECT_EQ(6, GetIdenticalPairsNum({1,1,1,1}));
}

UTEST(GetIdenticalPairsNum, 3) {
    EXPECT_EQ(0, GetIdenticalPairsNum({1,2,3}));
}
