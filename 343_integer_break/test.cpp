#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetMaxProduct, 1) {
    EXPECT_EQ(1, GetMaxProduct(2));
}

UTEST(GetMaxProduct, 2) {
    EXPECT_EQ(36, GetMaxProduct(10));
}

UTEST(GetMaxProduct, 3) {
    EXPECT_EQ(59049, GetMaxProduct(30));
}
