#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(CountVowelPermutation, 1) {
    EXPECT_EQ(5, CountVowelPermutation(1));
}

UTEST(CountVowelPermutation, 2) {
    EXPECT_EQ(10, CountVowelPermutation(2));
}

UTEST(CountVowelPermutation, 3) {
    EXPECT_EQ(68, CountVowelPermutation(5));
}
