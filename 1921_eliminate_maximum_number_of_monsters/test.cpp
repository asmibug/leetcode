#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetMaximumEliminationsSort, 1) {
    EXPECT_EQ(3, GetMaximumEliminationsSort({1,3,4}, {1,1,1}));
}

UTEST(GetMaximumEliminationsSort, 2) {
    EXPECT_EQ(1, GetMaximumEliminationsSort({1,1,2,3}, {1,1,1,1}));
}

UTEST(GetMaximumEliminationsSort, 3) {
    EXPECT_EQ(1, GetMaximumEliminationsSort({3,2,4}, {5,3,2}));
}


UTEST(GetMaximumEliminationsBucket, 1) {
    EXPECT_EQ(3, GetMaximumEliminationsBucket({1,3,4}, {1,1,1}));
}

UTEST(GetMaximumEliminationsBucket, 2) {
    EXPECT_EQ(1, GetMaximumEliminationsBucket({1,1,2,3}, {1,1,1,1}));
}

UTEST(GetMaximumEliminationsBucket, 3) {
    EXPECT_EQ(1, GetMaximumEliminationsBucket({3,2,4}, {5,3,2}));
}

UTEST(GetMaximumEliminationsBucket, 4) {
    EXPECT_EQ(2, GetMaximumEliminationsBucket({1,2,2,3}, {1,1,1,1}));
}
