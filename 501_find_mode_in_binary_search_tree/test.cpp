#include <optional>

#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

TreeNode* CreateNode(const std::vector<std::optional<int>>& values,
                     unsigned idx,
                     std::vector<TreeNode>* tree) {
    if (idx >= values.size() || !values[idx].has_value()) {
        return nullptr;
    }
    tree->emplace_back(values[idx].value(),
                       CreateNode(values, 2 * idx + 1, tree),
                       CreateNode(values, 2 * idx + 2, tree));
    return &tree->back();
}

std::vector<TreeNode> BuildTree(const std::vector<std::optional<int>>& values) {
    std::vector<TreeNode> tree;
    tree.reserve(values.size());
    CreateNode(values, 0, &tree);
    return tree;
}

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    auto tree = BuildTree({1,std::nullopt,2,std::nullopt,std::nullopt,2}); \
    std::vector<int> result = func(&tree.back()); \
    ASSERT_EQ(1u, result.size()); \
    EXPECT_EQ(2, result[0]); \
} \
UTEST(func, 2) { \
    auto tree = BuildTree({0}); \
    std::vector<int> result = func(&tree.back()); \
    ASSERT_EQ(1u, result.size()); \
    EXPECT_EQ(0, result[0]); \
} \

INSERT_TESTS(GetModeListTwoPasses)
INSERT_TESTS(GetModeListOnePass)
INSERT_TESTS(GetModeListOnePassIterative)
INSERT_TESTS(GetModeListMorrisSimple)
INSERT_TESTS(GetModeListMorrisRepair)
