#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetLastMoment, 1) {
    EXPECT_EQ(4, GetLastMoment(4, {4,3}, {0,1}));
}

UTEST(GetLastMoment, 2) {
    EXPECT_EQ(7, GetLastMoment(7, {}, {0,1,2,3,4,5,6,7}));
}

UTEST(GetLastMoment, 3) {
    EXPECT_EQ(7, GetLastMoment(7, {0,1,2,3,4,5,6,7}, {}));
}
