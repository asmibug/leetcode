#include <algorithm>
#include <climits>
#include <queue>
#include <vector>

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

std::vector<int> GetMaxForLevels(const TreeNode* root) {
    if (!root) {
        return {};
    }
    std::vector<int> result;
    std::queue<const TreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
        int max = INT_MIN;
        for (int i = queue.size(); i > 0; --i) {
            auto node = queue.front();
            queue.pop();
            if (node->val > max) {
                max = node->val;
            }
            for (auto child : {node->left, node->right}) {
                if (child) {
                    queue.push(child);
                }
            }
        }
        result.push_back(max);
    }
    return result;
}

using std::vector;

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        return GetMaxForLevels(root);
    }
};
