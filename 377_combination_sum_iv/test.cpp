#include "lib.cpp"  // GetCombinationsNumIterative GetCombinationsNumRecursive

#include "utest.h"  // EXPECT_TRUE UTEST UTEST_MAIN

UTEST(Utest, CanaryTest) {
    EXPECT_TRUE(true);
}

UTEST(GetCombinationsNumRecursive, 2_1) {
    EXPECT_EQ(0, GetCombinationsNumRecursive({2}, 1));
}

UTEST(GetCombinationsNumRecursive, 1_1) {
    EXPECT_EQ(1, GetCombinationsNumRecursive({1}, 1));
}

UTEST(GetCombinationsNumRecursive, 1_2_2) {
    EXPECT_EQ(2, GetCombinationsNumRecursive({1, 2}, 2));
}

UTEST(GetCombinationsNumRecursive, 1_2_3_4) {
    EXPECT_EQ(7, GetCombinationsNumRecursive({1, 2, 3}, 4));
}

UTEST(GetCombinationsNumIterative, 2_1) {
    EXPECT_EQ(0, GetCombinationsNumIterative({2}, 1));
}

UTEST(GetCombinationsNumIterative, 1_1) {
    EXPECT_EQ(1, GetCombinationsNumIterative({1}, 1));
}

UTEST(GetCombinationsNumIterative, 1_2_2) {
    EXPECT_EQ(2, GetCombinationsNumIterative({1, 2}, 2));
}

UTEST(GetCombinationsNumIterative, 1_2_3_4) {
    EXPECT_EQ(7, GetCombinationsNumIterative({1, 2, 3}, 4));
}

UTEST_MAIN();
