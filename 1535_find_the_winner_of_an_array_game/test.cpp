#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetWinner, 1) {
    EXPECT_EQ(5, GetWinner({2,1,3,5,4,6,7}, 2));
}

UTEST(GetWinner, 2) {
    EXPECT_EQ(3, GetWinner({3,2,1}, 10));
}
