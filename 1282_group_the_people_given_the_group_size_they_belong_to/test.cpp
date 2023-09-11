#include "lib.cpp"

#include "utest.h"

UTEST(Utest, CanaryTest) {
    EXPECT_TRUE(true);
}

namespace {  // auxiliary
    bool IsValid(const std::vector<std::vector<int>>& groups,
            std::vector<int> group_sizes) {
        int total_elements = group_sizes.size();
        for (auto& group : groups) {
            if (group.empty()) {
                return false;
            }
            for (int idx : group) {
                int group_size = group.size();
                if (idx >= total_elements || group_sizes[idx] != group_size) {
                    return false;
                }
                group_sizes[idx] = 0;
            }
        }
        for (int s : group_sizes) {
            if (s != 0) {
                return false;
            }
        }
        return true;
    }

    bool CheckGetGroups(const std::vector<int>& group_sizes) {
        return IsValid(GetGroups(group_sizes), group_sizes);
    }
}

UTEST(IsValid, Tests) {
    EXPECT_TRUE(IsValid({{0}}, {1}));
    EXPECT_FALSE(IsValid({{0}, {}}, {1}));
    EXPECT_FALSE(IsValid({{1}}, {1}));
    EXPECT_FALSE(IsValid({{0}, {0}}, {1}));
    EXPECT_TRUE(IsValid({{0, 1}}, {2, 2}));
    EXPECT_FALSE(IsValid({{0}, {1}}, {2, 2}));
    EXPECT_FALSE(IsValid({{0, 1}}, {2, 2, 1}));
}

UTEST(GetGroups, Tests) {
    EXPECT_TRUE(CheckGetGroups({1}));
    EXPECT_TRUE(CheckGetGroups({1, 1}));
    EXPECT_TRUE(CheckGetGroups({2, 2}));
    EXPECT_TRUE(CheckGetGroups({2, 2, 1}));
    EXPECT_TRUE(CheckGetGroups({2, 1, 2}));
}

UTEST_MAIN();
