#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(Has132PatternIntervals, 1) {
    EXPECT_FALSE(Has132PatternIntervals({1,2,3,4}));
}

UTEST(Has132PatternIntervals, 2) {
    EXPECT_TRUE(Has132PatternIntervals({3,1,4,2}));
}

UTEST(Has132PatternIntervals, 3) {
    EXPECT_TRUE(Has132PatternIntervals({-1,3,2,0}));
}

UTEST(Has132PatternIntervals, 4) {
    EXPECT_TRUE(Has132PatternIntervals({1,4,0,-1,-2,-3,-1,-2}));
}


UTEST(Has132PatternMinStack, 1) {
    EXPECT_FALSE(Has132PatternMinStack({1,2,3,4}));
}

UTEST(Has132PatternMinStack, 2) {
    EXPECT_TRUE(Has132PatternMinStack({3,1,4,2}));
}

UTEST(Has132PatternMinStack, 3) {
    EXPECT_TRUE(Has132PatternMinStack({-1,3,2,0}));
}

UTEST(Has132PatternMinStack, 4) {
    EXPECT_TRUE(Has132PatternMinStack({1,4,0,-1,-2,-3,-1,-2}));
}


UTEST(Has132PatternStack, 1) {
    EXPECT_FALSE(Has132PatternStack({1,2,3,4}));
}

UTEST(Has132PatternStack, 2) {
    EXPECT_TRUE(Has132PatternStack({3,1,4,2}));
}

UTEST(Has132PatternStack, 3) {
    EXPECT_TRUE(Has132PatternStack({-1,3,2,0}));
}

UTEST(Has132PatternStack, 4) {
    EXPECT_TRUE(Has132PatternStack({1,4,0,-1,-2,-3,-1,-2}));
}

UTEST(Has132PatternStack, 5) {
    EXPECT_TRUE(Has132PatternStack({3,5,0,3,4}));
}

UTEST(Has132PatternStack, 6) {
    EXPECT_TRUE(Has132PatternStack({-2,1,2,-2,1,2}));
}