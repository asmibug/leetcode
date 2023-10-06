#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GetMajorityElements, 1) {
    std::vector<int> res = GetMajorityElements({3, 2 ,3});
    ASSERT_EQ(1u, res.size());
    EXPECT_EQ(3, res[0]);
}

UTEST(GetMajorityElements, 2) {
    auto res = GetMajorityElements({1});
    ASSERT_EQ(1u, res.size());
    EXPECT_EQ(1, res[0]);
}

UTEST(GetMajorityElements, 3) {
    auto res = GetMajorityElements({1, 2});
    ASSERT_EQ(2u, res.size());
    EXPECT_EQ(1, res[0]);
    EXPECT_EQ(2, res[1]);
}
