#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    EXPECT_TRUE(func("abcdeca", 2)); \
    EXPECT_TRUE(func("abbababa", 1)); \
} \

INSERT_TESTS(IsValidPalindromeRecursive)
INSERT_TESTS(IsValidPalindromeIterative)
