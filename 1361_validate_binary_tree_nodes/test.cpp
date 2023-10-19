#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(ValidateDfsRecursive, 1) {
    EXPECT_TRUE(ValidateDfsRecursive(4, {1,-1,3,-1}, {2,-1,-1,-1}));
}

UTEST(ValidateDfsRecursive, 2) {
    EXPECT_FALSE(ValidateDfsRecursive(4, {1,-1,3,-1}, {2,3,-1,-1}));
}

UTEST(ValidateDfsRecursive, 3) {
    EXPECT_FALSE(ValidateDfsRecursive(2, {1,0}, {-1,-1}));
}

UTEST(ValidateDfsRecursive, 4) {
    EXPECT_TRUE(ValidateDfsRecursive(4, {3,-1,1,-1}, {-1,-1,0,-1}));
}


UTEST(ValidateDfsIterative, 1) {
    EXPECT_TRUE(ValidateDfsIterative(4, {1,-1,3,-1}, {2,-1,-1,-1}));
}

UTEST(ValidateDfsIterative, 2) {
    EXPECT_FALSE(ValidateDfsIterative(4, {1,-1,3,-1}, {2,3,-1,-1}));
}

UTEST(ValidateDfsIterative, 3) {
    EXPECT_FALSE(ValidateDfsIterative(2, {1,0}, {-1,-1}));
}

UTEST(ValidateDfsIterative, 4) {
    EXPECT_TRUE(ValidateDfsIterative(4, {3,-1,1,-1}, {-1,-1,0,-1}));
}


UTEST(ValidateBfs, 1) {
    EXPECT_TRUE(ValidateBfs(4, {1,-1,3,-1}, {2,-1,-1,-1}));
}

UTEST(ValidateBfs, 2) {
    EXPECT_FALSE(ValidateBfs(4, {1,-1,3,-1}, {2,3,-1,-1}));
}

UTEST(ValidateBfs, 3) {
    EXPECT_FALSE(ValidateBfs(2, {1,0}, {-1,-1}));
}

UTEST(ValidateBfs, 4) {
    EXPECT_TRUE(ValidateBfs(4, {3,-1,1,-1}, {-1,-1,0,-1}));
}
