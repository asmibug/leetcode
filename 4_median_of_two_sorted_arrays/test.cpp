#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(FindMedianSortedArraysMerge, 1) {
    EXPECT_NEAR(2, FindMedianSortedArraysMerge({1, 3}, {2}), 1e-9);
}

UTEST(FindMedianSortedArraysMerge, 2) {
    EXPECT_NEAR(2.5, FindMedianSortedArraysMerge({1, 2}, {3, 4}), 1e-9);
}


UTEST(FindMedianSortedArrayRecursive, 1) {
    EXPECT_NEAR(2, FindMedianSortedArrayRecursive({1, 3}, {2}), 1e-9);
}

UTEST(FindMedianSortedArrayRecursive, 2) {
    EXPECT_NEAR(2.5, FindMedianSortedArrayRecursive({1, 2}, {3, 4}), 1e-9);
}