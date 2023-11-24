#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetMaxDistance, 1) {
    EXPECT_EQ(4, GetMaxDistance({{1,2,3},{4,5},{1,2,3}}));
}

UTEST(GetMaxDistance, 2) {
    EXPECT_EQ(0, GetMaxDistance({{1},{1}}));
}
