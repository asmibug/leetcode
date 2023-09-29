#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetIncreasingSubarraysCount, 1) {
    EXPECT_EQ(10, GetIncreasingSubarraysCount({1,3,5,4,4,6}));
}

UTEST(GetIncreasingSubarraysCount, 2) {
    EXPECT_EQ(15, GetIncreasingSubarraysCount({1,2,3,4,5}));
}
