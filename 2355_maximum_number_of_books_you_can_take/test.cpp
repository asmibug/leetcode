#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetMaxBooks, 1) {
    EXPECT_EQ(19, GetMaxBooks({8,5,2,7,9}));
}

UTEST(GetMaxBooks, 2) {
    EXPECT_EQ(12, GetMaxBooks({7,0,3,4,5}));
}

UTEST(GetMaxBooks, 3) {
    EXPECT_EQ(13, GetMaxBooks({8,2,3,7,3,4,0,1,4,3}));
}
