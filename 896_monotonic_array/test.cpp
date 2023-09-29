#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(IsMonotonic, 1) {
    EXPECT_TRUE(IsMonotonic({1, 2, 2, 3}));
}

UTEST(IsMonotonic, 2) {
    EXPECT_TRUE(IsMonotonic({6, 5, 4, 4}));
}

UTEST(IsMonotonic, 3) {
    EXPECT_FALSE(IsMonotonic({1,3,2}));
}
