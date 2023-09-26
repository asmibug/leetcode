#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(FindTheDifference, 1) {
    EXPECT_TRUE('e' == FindTheDifference("abcd", "abcde"));
}

UTEST(FindTheDifference, 2) {
    EXPECT_TRUE('y' == FindTheDifference("", "y"));
}
