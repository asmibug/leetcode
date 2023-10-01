#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST (ReverseWords, 1) {
    std::string result = ReverseWords("Let's take LeetCode contest");
    ASSERT_STREQ("s'teL ekat edoCteeL tsetnoc", result.c_str());
}

UTEST(ReverseWords, 2) {
    auto result = ReverseWords("God Ding");
    ASSERT_STREQ("doG gniD", result.c_str());
}
