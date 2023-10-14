#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetMinCostRecursiveHash, 1) {
    EXPECT_EQ(3, GetMinCostRecursiveHash({1,2,3,2}, {1,2,3,2}));
}

UTEST(GetMinCostRecursiveHash, 2) {
    EXPECT_EQ(4, GetMinCostRecursiveHash({2,3,4,2}, {1,1,1,1}));
}


UTEST(GetMinCostRecursiveVector, 1) {
    EXPECT_EQ(3, GetMinCostRecursiveVector({1,2,3,2}, {1,2,3,2}));
}

UTEST(GetMinCostRecursiveVector, 2) {
    EXPECT_EQ(4, GetMinCostRecursiveVector({2,3,4,2}, {1,1,1,1}));
}


UTEST(GetMinCostIterative, 1) {
    EXPECT_EQ(3, GetMinCostIterative({1,2,3,2}, {1,2,3,2}));
}

UTEST(GetMinCostIterative, 2) {
    EXPECT_EQ(4, GetMinCostIterative({2,3,4,2}, {1,1,1,1}));
}
