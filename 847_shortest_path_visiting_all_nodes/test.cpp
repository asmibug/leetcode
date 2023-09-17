#include "lib.cpp"

#include "utest.h"

UTEST(GetShortestPathLength, 1) {
    EXPECT_EQ(4, GetShortestPathLength({{1, 2, 3}, {0}, {0}, {0}}));
}

UTEST(GetShortestPathLength, 2) {
    EXPECT_EQ(4, GetShortestPathLength(
        {{1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2}}));
}

UTEST(GetShortestPathLength, 3) {
    EXPECT_EQ(17, GetShortestPathLength(
        {{7}, {3}, {3, 9}, {1, 2, 4, 5, 7, 11}, {3}, {3}, {9}, {3, 10, 8, 0},
         {7}, {11, 6, 2}, {7}, {3, 9}}));
}

UTEST_MAIN()
