#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetReductionsNum, 1) {
    EXPECT_EQ(3, GetReductionsNum({5,1,3}));
}

UTEST(GetReductionsNum, 2) {
    EXPECT_EQ(0, GetReductionsNum({1,1,1}));
}

UTEST(GetReductionsNum, 3) {
    EXPECT_EQ(4, GetReductionsNum({1,1,2,2,3}));
}

UTEST(GetReductionsNum, 4) {
    EXPECT_EQ(45, GetReductionsNum({7,9,10,8,6,4,1,5,2,3}));
}
