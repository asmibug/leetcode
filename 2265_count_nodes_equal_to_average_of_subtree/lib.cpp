/**/
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/**/

std::pair<int, int> GetSumAndNum(const TreeNode* node, int* count) {
    if (!node) {
        return {0, 0};
    }
    auto [left_sum, left_num] = GetSumAndNum(node->left, count);
    auto [right_sum, right_num] = GetSumAndNum(node->right, count);
    int sum = node->val + left_sum + right_sum;
    int num = 1 + left_num + right_num;
    if (node->val == sum / num) {
        ++*count;
    }
    return {sum, num};
}

int GetNumNodesWithValueAverage(const TreeNode* root) {
    int count = 0;
    GetSumAndNum(root, &count);
    return count;
}

class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        return GetNumNodesWithValueAverage(root);
    }
};
