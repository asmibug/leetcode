#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetMinOperations, 1) {
    EXPECT_EQ(0, GetMinOperations({4,2,5,3}));
}

UTEST(GetMinOperations, 2) {
    EXPECT_EQ(1, GetMinOperations({1,2,3,5,6}));
}

UTEST(GetMinOperations, 3) {
    EXPECT_EQ(3, GetMinOperations({1,10,100,1000}));
}

UTEST(GetMinOperations, 4) {
    EXPECT_EQ(2, GetMinOperations({8,5,9,9,8,4}));
}

UTEST(GetMinOperations, 5) {
    EXPECT_EQ(5, GetMinOperations({41,33,29,33,35,26,47,24,18,28}));
}
