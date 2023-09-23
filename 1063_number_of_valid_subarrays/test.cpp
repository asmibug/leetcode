#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(CountValidSubarrays, 1) {
    EXPECT_EQ(11, CountValidSubarrays({1, 4, 2, 5, 3}));
}

UTEST(CountValidSubarrays, 2) {
    EXPECT_EQ(3, CountValidSubarrays({3, 2, 1}));
}

UTEST(CountValidSubarrays, 3) {
    EXPECT_EQ(6, CountValidSubarrays({2, 2, 2}));
}