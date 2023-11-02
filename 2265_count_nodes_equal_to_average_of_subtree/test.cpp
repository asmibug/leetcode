#include <optional>
#include <vector>

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

UTEST(GetNumNodesWithValueAverage, 1) {
    auto tree = BuildTree({4,8,5,0,1,std::nullopt,6});
    EXPECT_EQ(5, GetNumNodesWithValueAverage(&tree.back()));
}

UTEST(GetNumNodesWithValueAverage, 2) {
    auto tree = BuildTree({1});
    EXPECT_EQ(1, GetNumNodesWithValueAverage(&tree.back()));
}
