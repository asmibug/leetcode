#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(FindInMountainArray, 1) {
    EXPECT_EQ(2, FindInMountainArray(3, std::vector<int>{1,2,3,4,5,3,1}));
}

UTEST(FindInMountainArray, 2) {
    EXPECT_EQ(-1, FindInMountainArray(3, std::vector<int>{0,1,2,4,2,1}));
}

UTEST(FindInMountainArray, 3) {
    EXPECT_EQ(2, FindInMountainArray(2, std::vector<int>{1,5,2}));
}
