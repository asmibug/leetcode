#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetMinTimeDfs, 1) {
    EXPECT_EQ(8, GetMinTimeDfs(3, {{1,3},{2,3}}, {3,2,5}));
}

UTEST(GetMinTimeDfs, 2) {
    EXPECT_EQ(12, GetMinTimeDfs(5, {{1,5},{2,5},{3,5},{3,4},{4,5}}, {1,2,3,4,5}));
}


UTEST(GetMinTimeKahn, 1) {
    EXPECT_EQ(8, GetMinTimeKahn(3, {{1,3},{2,3}}, {3,2,5}));
}

UTEST(GetMinTimeKahn, 2) {
    EXPECT_EQ(12, GetMinTimeKahn(5, {{1,5},{2,5},{3,5},{3,4},{4,5}}, {1,2,3,4,5}));
}
