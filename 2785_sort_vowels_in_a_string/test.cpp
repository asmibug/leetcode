#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(SortVowels, 1) {
    std::string result = SortVowels("lEetcOde");
    EXPECT_STREQ("lEOtcede", result.c_str());
}

UTEST(SortVowels, 2) {
    auto result = SortVowels("lYmpH");
    EXPECT_STREQ("lYmpH", result.c_str());
}
