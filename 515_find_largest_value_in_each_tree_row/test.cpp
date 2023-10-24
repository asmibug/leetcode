#include "lib.cpp"

#include <list>
#include <optional>

#include "utest.h"

UTEST_MAIN()

TreeNode* MakeNode(const std::vector<std::optional<int>>& values,
                   unsigned idx,
                   std::list<TreeNode>& nodes) {
    if (idx >= values.size() || !values[idx].has_value()) {
        return nullptr;
    }
    nodes.push_back(TreeNode(values[idx].value()));
    TreeNode* result = &nodes.back();
    result->left = MakeNode(values, 2 * idx + 1, nodes);
    result->right = MakeNode(values, 2 * idx + 2, nodes);
    return result;
}

std::list<TreeNode> MakeTree(const std::vector<std::optional<int>>& values) {
    std::list<TreeNode> nodes;
    MakeNode(values, 0, nodes);
    return nodes;
}

#define ASSERT_VECT(expected, result) do { \
    auto _expected = expected; \
    auto _result = result; \
    ASSERT_EQ(_expected.size(), _result.size()); \
    for (unsigned i = 0; i < _expected.size(); ++i) { \
        EXPECT_EQ(_expected[i], _result[i]); \
    } \
} while (0) \

UTEST(GetMaxForLevels, 1) {
    auto tree = MakeTree({1,3,2,5,3,std::nullopt,9});
    ASSERT_VECT((std::vector{1,3,9}), GetMaxForLevels(&tree.front()));
}

UTEST(GetMaxForLevels, 2) {
    auto tree = MakeTree({1,2,3});
    ASSERT_VECT((std::vector{1,3}), GetMaxForLevels(&tree.front()));
}
