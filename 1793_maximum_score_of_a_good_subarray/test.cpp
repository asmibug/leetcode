#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetMaxScore, 1) {
    EXPECT_EQ(15, GetMaxScore({1,4,3,7,4,5}, 3));
}

UTEST(GetMaxScore, 2) {
    EXPECT_EQ(20, GetMaxScore({5,5,4,5,4,1,1,1}, 0));
}

UTEST(GetMaxScore, 3) {
    EXPECT_EQ(9732, GetMaxScore(
        {6569,9667,3148,7698,1622,2194,793,9041,1670,1872}, 5));
}
