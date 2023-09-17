#include "lib.cpp"

#include "utest.h"

UTEST(GetMinEffort, 1) {
    EXPECT_EQ(2, GetMinEffort({{1, 2, 2}, {3, 8, 2}, {5, 3, 5}}));
}

UTEST(GetMinEffort, 2) {
    EXPECT_EQ(1, GetMinEffort({{1, 2, 3}, {3, 8, 4}, {5, 3, 5}}));
}

UTEST(GetMinEffort, 3) {
    EXPECT_EQ(0, GetMinEffort(
        {{1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1},
         {1, 1, 1, 2, 1}}));
}

UTEST_MAIN()
