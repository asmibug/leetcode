#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetAmount, 1) {
    EXPECT_NEAR(0, GetAmount(1, 1, 1), 1e-9);
}

UTEST(GetAmount, 2) {
    EXPECT_NEAR(0.5, GetAmount(2, 1, 1), 1e-9);
}

UTEST(GetAmount, 3) {
    EXPECT_NEAR(1, GetAmount(100000009, 33, 17), 1e-9);
}

UTEST(GetAmount, 4) {
    EXPECT_NEAR(0.18750, GetAmount(25, 6, 1), 1e-9);
}
