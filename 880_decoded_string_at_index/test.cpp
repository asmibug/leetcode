#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(DecodeAtIndex, 1) {
    std::string result = DecodeAtIndex("leet2code3", 10);
    EXPECT_STREQ("o", result.c_str());
}

UTEST(DecodeAtIndex, 2) {
    auto result = DecodeAtIndex("ha22", 5);
    EXPECT_STREQ("h", result.c_str());
}

UTEST(DecodeAtIndex, 3) {
    auto result = DecodeAtIndex("a2345678999999999999999", 1);
    EXPECT_STREQ("a", result.c_str());
}
