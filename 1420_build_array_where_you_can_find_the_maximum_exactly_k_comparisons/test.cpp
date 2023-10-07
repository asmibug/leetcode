#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetNumberRecursive, 1) {
    EXPECT_EQ(6, GetNumberRecursive(2, 3, 1));
}

UTEST(GetNumberRecursive, 2) {
    EXPECT_EQ(0, GetNumberRecursive(5, 2, 3));
}

UTEST(GetNumberRecursive, 3) {
    EXPECT_EQ(1, GetNumberRecursive(9, 1, 1));
}

UTEST(GetNumberRecursive, 4) {
    EXPECT_EQ(34549172, GetNumberRecursive(50, 100, 25));
}


UTEST(GetNumberIterative, 1) {
    EXPECT_EQ(6, GetNumberIterative(2, 3, 1));
}

UTEST(GetNumberIterative, 2) {
    EXPECT_EQ(0, GetNumberIterative(5, 2, 3));
}

UTEST(GetNumberIterative, 3) {
    EXPECT_EQ(1, GetNumberIterative(9, 1, 1));
}

UTEST(GetNumberIterative, 4) {
    EXPECT_EQ(34549172, GetNumberIterative(50, 100, 25));
}
