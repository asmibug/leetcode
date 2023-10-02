#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(IsAliceWinner, 1) {
    EXPECT_TRUE(IsAliceWinner("AAABABB"));
}

UTEST(IsAliceWinner, 2) {
    EXPECT_FALSE(IsAliceWinner("AA"));
}

UTEST(IsAliceWinner, 3) {
    EXPECT_FALSE(IsAliceWinner("ABBBBBBBAAA"));
}
