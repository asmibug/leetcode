#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetTotalDistance, 1) {
    EXPECT_EQ(12, GetTotalDistance(5, 7, {2,2}, {4,4}, {{3,0}, {2,5}}));
}

UTEST(GetTotalDistance, 2) {
    EXPECT_EQ(3, GetTotalDistance(1, 3, {0,1}, {0,0}, {{0,2}}));
}
