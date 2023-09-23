#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(IsPredecessor, UnitTest) {
    EXPECT_TRUE(IsPredecessor("", "a"));
    EXPECT_FALSE(IsPredecessor("", "aa"));
    EXPECT_TRUE(IsPredecessor("abc", "adbc"));
    EXPECT_FALSE(IsPredecessor("abc", "adcb"));
}

UTEST(GetLongestChainLenFirst, 1) {
    EXPECT_EQ(4, GetLongestChainLenFirst({"a","b","ba","bca","bda","bdca"}));
}

UTEST(GetLongestChainLenFirst, 2) {
    EXPECT_EQ(5, GetLongestChainLenFirst({"xbc","pcxbcf","xb","cxbc","pcxbc"}));
}

UTEST(GetLongestChainLenFirst, 3) {
    EXPECT_EQ(1, GetLongestChainLenFirst({"abcd","dbqca"}));
}

UTEST(GetLongestChainLen, 1) {
    EXPECT_EQ(4, GetLongestChainLen({"a","b","ba","bca","bda","bdca"}));
}

UTEST(GetLongestChainLen, 2) {
    EXPECT_EQ(5, GetLongestChainLen({"xbc","pcxbcf","xb","cxbc","pcxbc"}));
}

UTEST(GetLongestChainLen, 3) {
    EXPECT_EQ(1, GetLongestChainLen({"abcd","dbqca"}));
}
