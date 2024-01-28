/**
 * Approaches:
 * 1) Recursion
 * 2) Reverse Preorder
 * 3) Save state for vertices in stack
 * 4) Save global state
 * 5) Use hash-set to remember seen vertices
 * 6) Use hash-set to remeber flag to_process
 * 7) Put vertex twice on stack
 * 8) Remember last processed vertex
 * 9) Move down as long as we can
 * 10) Morris generic
 * 11) Morris with dummy node
*/

#include <algorithm>
#include <unordered_set>
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


void PostorderRecursion(TreeNode* root, std::vector<int>* out) {
    if (!root) {
        return;
    }
    PostorderRecursion(root->left, out);
    PostorderRecursion(root->right, out);
    out->push_back(root->val);
}

std::vector<int> PostorderRecursive(TreeNode* root) {
    std::vector<int> res;
    PostorderRecursion(root, &res);
    return res;
}


std::vector<int> PostorderIterativeByReversePreorder(TreeNode* root) {
    std::vector<int> res;
    auto node = root;
    std::vector stack = {root};
    while (!stack.empty()) {
        if (node) {
            res.push_back(node->val);
            if (node->left) {
                stack.push_back(node->left);
            }
            node = node->right;
        } else {
            node = stack.back();
            stack.pop_back();
        }
    }
    std::ranges::reverse(res);
    return res;
}


enum class State {
    LEFT,
    RIGHT,
    UP,
};

std::vector<int> PostorderIterativeByStateStore(TreeNode* root) {
    std::vector<int> res;
    if (!root) {
        return res;
    }
    std::vector stack = {std::pair{root, State::LEFT}};
    while (!stack.empty()) {
        auto [node, state] = stack.back();
        switch (state) {
        case State::LEFT:
            // here we can call preorder callback
            stack.back().second = State::RIGHT;
            if (node->left) {
                stack.push_back({node->left, State::LEFT});
            }
            break;
        case State::RIGHT:
            // here we can call inorder callback
            stack.back().second = State::UP;
            if (node->right) {
                stack.push_back({node->right, State::LEFT});
            }
            break;
        case State::UP:
            res.push_back(node->val);
            stack.pop_back();
            break;
        default:
            throw std::runtime_error("Unknown state");
        }
    }
    return res;
}


std::vector<int> PostorderIterativeByState(TreeNode* root) {
    std::vector<int> res;
    if (!root) {
        return res;
    }
    auto node = root;
    std::vector<decltype(root)> parents;
    State state = State::LEFT;
    while (true) {
        switch (state) {
        case State::LEFT:
            // here we can call preorder callback
            if (node->left) {
                parents.push_back(node);
                node = node->left;
            } else {
                state = State::RIGHT;
            }
            break;
        case State::RIGHT:
            // here we can call inorder callback
            if (node->right) {
                parents.push_back(node);
                node = node->right;
                state = State::LEFT;
            } else {
                state = State::UP;
            }
            break;
        case State::UP:
            res.push_back(node->val);
            if (parents.empty()) {
                return res;
            }
            state = node == parents.back()->left ? State::RIGHT : State::UP;
            node = parents.back();
            parents.pop_back();
            break;
        default:
            throw std::runtime_error("Unknown state");
        }
    }
}


std::vector<int> PostorderIterativeBySeen(TreeNode* root) {
    if (!root) {
        return {};
    }
    std::vector<int> res;
    std::unordered_set<decltype(root)> seen;
    std::vector stack = {root};
    while (!stack.empty()) {
        auto node = stack.back();
        if (!seen.contains(node)) {
            // here we can call preorder callback
        }
        seen.insert(node);
        if (node->left && !seen.contains(node->left)) {
            stack.push_back(node->left);
        } else if (node->right && !seen.contains(node->right)) {
            // here we can call inorder callback
            stack.push_back(node->right);
        } else {
            if (!node->right) {
                // here we can call inorder callback
            }
            res.push_back(node->val);
            stack.pop_back();
        }
    }
    return res;
}


std::vector<int> PostorderIterativeByHashset(TreeNode* root) {
    std::vector<int> res;
    std::unordered_set<TreeNode*> to_process;
    auto node = root;
    std::vector<TreeNode*> stack;
    while (node || !stack.empty()) {
        if (node) {
            // here we can call preorder callback
            stack.push_back(node);
            node = node->left;
        } else {
            node = stack.back();
            if (!to_process.contains(node)) {
                // here we can call inorder callback
                to_process.insert(node);
                node = node->right;
            } else {
                res.push_back(node->val);
                to_process.erase(node);
                stack.pop_back();
                node = nullptr;
            }
        }
    }
    return res;
}


std::vector<int> PostorderIterativeByDouble(TreeNode* root) {
    std::vector<int> res;
    auto cur = root;
    std::vector<TreeNode*> stack;
    while (cur || !stack.empty()) {
        if (cur) {
            // here we can call preorder callback
            stack.push_back(cur);
            stack.push_back(cur);
            cur = cur->left;
        } else {
            auto node = stack.back();
            stack.pop_back();
            if (!stack.empty() && stack.back() == node) {
                // here we can call inorder callback
                cur = node->right;
            } else {
                res.push_back(node->val);
            }
        }
    }
    return res;
}


std::vector<int> PostorderIterativeByLastProcessed(TreeNode* root) {
    std::vector<int> res;
    auto last_processed = root;
    auto cur = root;
    std::vector<decltype(root)> stack;
    while (cur || !stack.empty()) {
        if (cur) {
            // here we can call preorder callback
            stack.push_back(cur);
            cur = cur->left;
        } else {
            auto node = stack.back();
            if (node->right != last_processed) {
                // here we can call inorder callback
            }
            if (node->right && node->right != last_processed) {
                cur = node->right;
            } else {
                res.push_back(node->val);
                last_processed = node;
                stack.pop_back();
            }
        }
    }
    return res;
}


std::vector<int> PostorderIterativeByMoveDown(TreeNode* root) {
    std::vector<int> res;
    auto cur = root;
    std::vector<decltype(root)> parents;
    while (cur || !parents.empty()) {
        if (cur) {
            // here we can call preorder callback
            parents.push_back(cur);
            if (cur->left) {
                cur = cur->left;
            } else {
                // here we can call inorder callback
                cur = cur->right;
            }
        } else {
            auto prev = parents.back();
            parents.pop_back();
            res.push_back(prev->val);
            if (!parents.empty() && prev == parents.back()->left) {
                // here we can call inorder callback
                cur = parents.back()->right;
            }
        }
    }
    return res;
}


template <typename Node>
Node* Reverse(Node* head) {
    Node* prev = nullptr;
    Node* cur = head;
    while (cur) {
        Node* next = cur->right;
        cur->right = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

template <typename Callback>
void DfsMorrisPostorder(TreeNode* root, Callback& callback) {
    if (!root) {
        return;
    }
    auto node = root;
    while (node) {
        bool first_time = true;
        bool go_left = true;
        auto left = node->left;
        if (left) {
            while (left->right && left->right != node) {
                left = left->right;
            }
            if (!left->right) {
                left->right = node;
            } else {
                left->right = nullptr;
                first_time = false;
                go_left = false;
            }
        } else {
            go_left = false;
        }
        if (first_time) {
            // call preorder callback here
        } else {
            Reverse(node->left);
            for (auto cur = left; cur; cur = cur->right) {
                callback(cur);
            }
            Reverse(left);
        }
        if (go_left) {
            node = node->left;
        } else {
            // call inorder callback here
            node = node->right;
        }
    }
    node = Reverse(root);
    for (auto cur = node; cur; cur = cur->right) {
        callback(cur);
    }
    Reverse(node);
}

std::vector<int> PostorderIterativeByMorris(TreeNode* root) {
    std::vector<int> res;
    auto callback = [&res](TreeNode* node) {res.push_back(node->val);};
    DfsMorrisPostorder(root, callback);
    return res;
}


template <typename Callback>
void DfsMorrisPostorderDummy(TreeNode* root, Callback& callback) {
    TreeNode dummy;
    dummy.left = root;
    auto node = &dummy;
    while (node) {
        if (node->left) {
            auto left = node->left;
            while (left->right && left->right != node) {
                left = left->right;
            }
            if (!left->right) {
                left->right = node;
                node = node->left;
            } else {
                left->right = nullptr;
                Reverse(node->left);
                for (auto cur = left; cur; cur = cur->right) {
                    callback(cur);
                }
                Reverse(left);
                node = node->right;
            }
        } else {
            node = node->right;
        }
    }
}

std::vector<int> PostorderIterativeByMorrisDummy(TreeNode* root) {
    std::vector<int> res;
    auto callback = [&res](TreeNode* node) {res.push_back(node->val);};
    DfsMorrisPostorderDummy(root, callback);
    return res;
}


///// Additional solutions (variants of above) /////

std::vector<int> PostorderIterativeByCycle(TreeNode* root) {
    std::vector<int> res;
    auto node = root;
    std::vector<decltype(root)> stack;
    while (node || !stack.empty()) {
        if (node) {
            // here we can call preorder callback
            stack.push_back(node);
            node = node->left;
        } else if (stack.back()->right) {
            // here we can call inorder callback
            node = stack.back()->right;
        } else {
            if (!stack.back()->right) {
                // here we can call inorder callback
            }
            do {
                node = stack.back();
                stack.pop_back();
                res.push_back(node->val);
            } while (!stack.empty() && node == stack.back()->right);
            node = nullptr;
        }
    }
    return res;
}


std::vector<int> PostorderIterativeByFlag(TreeNode* root) {
    std::vector<int> res;
    bool moved_up = false;
    auto node = root;
    std::vector<decltype(root)> stack;
    while (true) {
        if (!moved_up) {
            while (node) {
                // here we can call preorder callback
                stack.push_back(node);
                node = node->left;
            }
        }
        if (stack.empty()) {
            break;
        }
        if (node != stack.back()->right) {
            node = stack.back()->right;
            moved_up = false;
        } else {
            node = stack.back();
            stack.pop_back();
            moved_up = true;
            res.push_back(node->val);
        }
    }
    return res;
}


std::vector<int> PostorderIterativeByPrev(TreeNode* root) {
    std::vector<int> res;
    auto prev = root;
    auto cur = root;
    std::vector stack = {root};
    while (!stack.empty()) {
        if (!cur || prev == cur->right) {
            if (cur) {
                res.push_back(cur->val);
            }
            prev = cur;
            cur = stack.back();
            stack.pop_back();
        } else {
            stack.push_back(cur);
            if (prev == cur->left) {
                prev = cur;
                cur = cur->right;
            } else {
                // here we can call preorder callback
                prev = cur;
                cur = cur->left;
            }
        }
    }
    return res;
}


using std::vector;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        return PostorderIterativeByMorrisDummy(root);
    }
};
