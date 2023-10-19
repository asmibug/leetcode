#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(BackspaceCompareConstruct, 1) {
    EXPECT_TRUE(BackspaceCompareConstruct("ab#c", "ad#c"));
}

UTEST(BackspaceCompareConstruct, 2) {
    EXPECT_TRUE(BackspaceCompareConstruct("ab##", "c#d#"));
}

UTEST(BackspaceCompareConstruct, 3) {
    EXPECT_FALSE(BackspaceCompareConstruct("a#c", "b"));
}


UTEST(BackspaceCompareBackwards, 1) {
    EXPECT_TRUE(BackspaceCompareBackwards("ab#c", "ad#c"));
}

UTEST(BackspaceCompareBackwards, 2) {
    EXPECT_TRUE(BackspaceCompareBackwards("ab##", "c#d#"));
}

UTEST(BackspaceCompareBackwards, 3) {
    EXPECT_FALSE(BackspaceCompareBackwards("a#c", "b"));
}
