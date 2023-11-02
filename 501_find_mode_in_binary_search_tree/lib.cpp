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

template <typename Callback>
void Dfs(const TreeNode* node, Callback& callback) {
    if (!node) {
        return;
    }
    Dfs(node->left, callback);
    callback(node->val);
    Dfs(node->right, callback);
}

struct Counter {
    int prev = 0;
    int count = 0;

    void operator()(int val) {
        if (val == prev) {
            ++count;
        } else {
            prev = val;
            count = 1;
        }
    }
};

struct MaxCountAccumulator : Counter {
    int max_count = 0;

    void operator()(int val) {
        Counter::operator()(val);
        if (count > max_count) {
            max_count = count;
        }
    }
};

class Appender : Counter {
public:
    Appender(int target_count, std::vector<int>& vect)
        : target_count_(target_count), vect_(vect) {
    }

    void operator()(int val) {
        Counter::operator()(val);
        if (count == target_count_) {
            vect_.push_back(val);
        }
    }

private:
    const int target_count_;
    std::vector<int>& vect_;
};

std::vector<int> GetModeListTwoPasses(const TreeNode* root) {
    MaxCountAccumulator counter;
    Dfs(root, counter);
    std::vector<int> result;
    Appender appender(counter.max_count, result);
    Dfs(root, appender);
    return result;
}

struct ModeCounter {
    std::vector<int> modes;
    int max_count = 0;
    int count = 0;
    int prev = 0;

    void operator()(int val) {
        if (val == prev) {
            ++count;
        } else {
            count = 1;
            prev = val;
        }
        if (count > max_count) {
            max_count = count;
            modes.resize(0);
        }
        if (count == max_count) {
            modes.push_back(val);
        }
    }
};

std::vector<int> GetModeListOnePass(const TreeNode* root) {
    ModeCounter counter;
    Dfs(root, counter);
    return counter.modes;
}

template <typename Callback>
void DfsIterative(const TreeNode* root, Callback& callback) {
    if (!root) {
        return;
    }
    auto node = root;
    std::vector<const TreeNode*> stack;
    while (node || !stack.empty()) {
        while (node) {
            stack.push_back(node);
            node = node->left;
        }
        node = stack.back();
        stack.pop_back();
        callback(node->val);
        node = node->right;
    }
}

std::vector<int> GetModeListOnePassIterative(const TreeNode* root) {
    ModeCounter counter;
    DfsIterative(root, counter);
    return counter.modes;
}

template <typename Callback>
void MorrisSimple(TreeNode* root, Callback& callback) {
    auto cur = root;
    while (cur) {
        if (cur->left) {
            auto left = cur->left;
            while (left->right) {
                left = left->right;
            }
            left->right = cur;
            auto next = cur->left;
            cur->left = nullptr;
            cur = next;
        } else {
            callback(cur->val);
            cur = cur->right;
        }
    }
}

std::vector<int> GetModeListMorrisSimple(TreeNode* root) {
    ModeCounter counter;
    MorrisSimple(root, counter);
    return counter.modes;
}

template <typename Callback>
void MorrisRepair(TreeNode* root, Callback& callback) {
    auto cur = root;
    while (cur) {
        bool go_right = false;
        if (cur->left) {
            auto left = cur->left;
            while (left->right && left->right != cur) {
                left = left->right;
            }
            if (!left->right) {
                left->right = cur;
                cur = cur->left;
            } else {
                left->right = nullptr;
                go_right = true;
            }
        } else {
            go_right = true;
        }
        if (go_right) {
            callback(cur->val);
            cur = cur->right;
        }
    }
}

std::vector<int> GetModeListMorrisRepair(TreeNode* root) {
    ModeCounter counter;
    MorrisRepair(root, counter);
    return counter.modes;
}

using std::vector;

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        return GetModeListMorrisRepair(root);
    }
};
