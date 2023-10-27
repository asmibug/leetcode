#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetLongestPalindromeSimple, 1) {
    auto result = GetLongestPalindromeSimple("babad");
    EXPECT_STREQ("bab", result.c_str());
}

UTEST(GetLongestPalindromeSimple, 2) {
    auto result = GetLongestPalindromeSimple("cbbd");
    EXPECT_STREQ("bb", result.c_str());
}

UTEST(GetLongestPalindromeSimple, 3) {
    auto result = GetLongestPalindromeSimple("bb");
    EXPECT_STREQ("bb", result.c_str());
}

UTEST(GetLongestPalindromeSimple, 4) {
    auto result = GetLongestPalindromeSimple("ccc");
    EXPECT_STREQ("ccc", result.c_str());
}


UTEST(GetLongestPalindromeManacher, 1) {
    auto result = GetLongestPalindromeManacher("babad");
    EXPECT_STREQ("bab", result.c_str());
}

UTEST(GetLongestPalindromeManacher, 2) {
    auto result = GetLongestPalindromeManacher("cbbd");
    EXPECT_STREQ("bb", result.c_str());
}

UTEST(GetLongestPalindromeManacher, 3) {
    auto result = GetLongestPalindromeManacher("bb");
    EXPECT_STREQ("bb", result.c_str());
}

UTEST(GetLongestPalindromeManacher, 4) {
    auto result = GetLongestPalindromeManacher("ccc");
    EXPECT_STREQ("ccc", result.c_str());
}
