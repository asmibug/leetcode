#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(IsSubsequence, 1) {
    EXPECT_TRUE(IsSubsequence("abc", "ahbgdc"));
}

UTEST(IsSubsequence, 2) {
    EXPECT_FALSE(IsSubsequence("axc", "ahbgdc"));
}
