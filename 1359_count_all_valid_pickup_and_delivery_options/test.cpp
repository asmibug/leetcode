#include "lib.cpp"

#include "utest.h"

UTEST(Utest, CanaryTest) {
    EXPECT_TRUE(true);
}

UTEST(CountOrders, 1) {
    EXPECT_EQ(1, CountOrders(1));
}

UTEST(CountOrders, 2) {
    EXPECT_EQ(6, CountOrders(2));
}

UTEST(CountOrders, 3) {
    EXPECT_EQ(90, CountOrders(3));
}

UTEST_MAIN();
