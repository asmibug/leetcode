#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetNumFactoredBinaryTreesSimple, 1) {
    EXPECT_EQ(3, GetNumFactoredBinaryTreesSimple({2,4}));
}

UTEST(GetNumFactoredBinaryTreesSimple, 2) {
    EXPECT_EQ(7, GetNumFactoredBinaryTreesSimple({2,4,5,10}));
}


UTEST(GetNumFactoredBinaryTreesOptimized, 1) {
    EXPECT_EQ(3, GetNumFactoredBinaryTreesOptimized({2,4}));
}

UTEST(GetNumFactoredBinaryTreesOptimized, 2) {
    EXPECT_EQ(7, GetNumFactoredBinaryTreesOptimized({2,4,5,10}));
}
