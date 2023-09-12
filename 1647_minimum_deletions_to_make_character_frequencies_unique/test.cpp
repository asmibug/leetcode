#include "lib.cpp"

#include "utest.h"

UTEST(Utest, CanaryTest) {
    EXPECT_TRUE(true);
}

UTEST(GetMinDeletions, Tests) {
    EXPECT_EQ(0, GetMinDeletions(""));
    EXPECT_EQ(0, GetMinDeletions("a"));
    EXPECT_EQ(1, GetMinDeletions("ab"));
    EXPECT_EQ(0, GetMinDeletions("abb"));
    EXPECT_EQ(2, GetMinDeletions("aabbbccc"));
    EXPECT_EQ(2, GetMinDeletions("ceabaacb"));
    EXPECT_EQ(2, GetMinDeletions("bbcebab"));
}

UTEST_MAIN()
