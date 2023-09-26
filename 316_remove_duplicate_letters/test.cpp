#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(RemoveDuplicateLetters, 1) {
    std::string result = RemoveDuplicateLetters("bcabc");
    EXPECT_STREQ("abc", result.c_str());
}

UTEST(RemoveDuplicateLetters, 2) {
    auto result = RemoveDuplicateLetters("cbacdcbc");
    EXPECT_STREQ("acdb", result.c_str());
}

UTEST(RemoveDuplicateLetters, 3) {
    auto result = RemoveDuplicateLetters("abacb");
    EXPECT_STREQ("abc", result.c_str());
}
