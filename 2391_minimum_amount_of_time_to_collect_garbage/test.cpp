#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetTotalTime, 1) {
    EXPECT_EQ(21, GetTotalTime({"G","P","GP","GG"}, {2,4,3}));
}

UTEST(GetTotalTime, 2) {
    EXPECT_EQ(37, GetTotalTime({"MMM","PGM","GP"}, {3,10}));
}
