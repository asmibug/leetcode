#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(FindDuplicateFloyd, 1) {
    EXPECT_EQ(2, FindDuplicateFloyd({1, 3, 4, 2, 2}));
}

UTEST(FindDuplicateFloyd, 2) {
    EXPECT_EQ(3, FindDuplicateFloyd({3, 1, 3, 4, 2}));
}

UTEST(FindDuplicateFloyd, 3) {
    EXPECT_EQ(2, FindDuplicateFloyd({2, 2, 2, 2, 2}));
}

UTEST(FindDuplicateBrent, 1) {
    EXPECT_EQ(2, FindDuplicateBrent({1, 3, 4, 2, 2}));
}

UTEST(FindDuplicateBrent, 2) {
    EXPECT_EQ(3, FindDuplicateBrent({3, 1, 3, 4, 2}));
}

UTEST(FindDuplicateBrent, 3) {
    EXPECT_EQ(2, FindDuplicateBrent({2, 2, 2, 2, 2}));
}
