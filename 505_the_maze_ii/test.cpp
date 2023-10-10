#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetShortestDistance, 1) {
    EXPECT_EQ(12, GetShortestDistance(
        {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}},
        {0,4}, {4,4}));
}

UTEST(GetShortestDistance, 2) {
    EXPECT_EQ(-1, GetShortestDistance(
        {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}},
        {0,4}, {3,2}));
}

UTEST(GetShortestDistance, 3) {
    EXPECT_EQ(-1, GetShortestDistance(
        {{0,0,0,0,0},{1,1,0,0,1},{0,0,0,0,0},{0,1,0,0,1},{0,1,0,0,0}},
        {4,3}, {0,1}));
}

UTEST(GetShortestDistance, 4) {
    EXPECT_EQ(26, GetShortestDistance(
        {{0,0,0,0,1,0,0},{0,0,1,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,1},
        {0,1,0,0,0,0,0},{0,0,0,1,0,0,0},{0,0,0,0,0,0,0},{0,0,1,0,0,0,1},
        {0,0,0,0,1,0,0}},
        {0,0}, {8,6}));
}

UTEST(GetShortestDistance, 5) {
    EXPECT_EQ(3, GetShortestDistance(
        {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}},
        {1,1}, {1,2}));
}
