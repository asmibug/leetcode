#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetMinKnightMovesHeap, 1) {
    EXPECT_EQ(1, GetMinKnightMovesHeap(2, 1));
}

UTEST(GetMinKnightMovesHeap, 2) {
    EXPECT_EQ(4, GetMinKnightMovesHeap(5, 5));
}

UTEST(GetMinKnightMovesHeap, 3) {
    EXPECT_EQ(81, GetMinKnightMovesHeap(-99, 142));
}