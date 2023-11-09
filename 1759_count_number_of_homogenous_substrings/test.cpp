#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(CountHomogenous, 1) {
    EXPECT_EQ(13, CountHomogenous("abbcccaa"));
}

UTEST(CountHomogenous, 2) {
    EXPECT_EQ(2, CountHomogenous("xy"));
}

UTEST(CountHomogenous, 3) {
    EXPECT_EQ(15, CountHomogenous("zzzzz"));
}
