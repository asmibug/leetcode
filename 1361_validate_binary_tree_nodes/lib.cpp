#include <numeric>
#include <queue>
#include <vector>

int GetRoot(const std::vector<int>& left, const std::vector<int>& right) {
    int n = left.size();
    std::vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        if (left[i] != -1) {
            visited[left[i]] = true;
        }
        if (right[i] != -1) {
            visited[right[i]] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            return i;
        }
    }
    return -1;
}

bool Dfs(int idx,
         const std::vector<int>& left, const std::vector<int>& right,
         std::vector<bool>& visited) {
    if (idx == -1) {
        return true;
    }
    if (visited[idx]) {
        return false;
    }
    visited[idx] = true;
    return (Dfs(left[idx], left, right, visited)
            && Dfs(right[idx], left, right, visited));
}

bool ValidateDfsRecursive(int n,
                          const std::vector<int>& left,
                          const std::vector<int>& right) {
    int root = GetRoot(left, right);
    if (root < 0) {
        return false;
    }
    std::vector<bool> visited(n, false);
    return (Dfs(root, left, right, visited)
            && std::accumulate(visited.begin(), visited.end(), 0) == n);
}

bool ValidateDfsIterative(int n,
                          const std::vector<int>& left,
                          const std::vector<int>& right) {
    int root = GetRoot(left, right);
    if (root < 0) {
        return false;
    }
    std::vector<bool> visited(n, false);
    std::vector<int> stack = {root};
    while (!stack.empty()) {
        int cur = stack.back();
        stack.pop_back();
        if (cur == -1) {
            continue;
        }
        if (visited[cur]) {
            return false;
        }
        visited[cur] = true;
        stack.push_back(right[cur]);
        stack.push_back(left[cur]);
    }
    return std::accumulate(visited.begin(), visited.end(), 0) == n;
}

bool ValidateBfs(int n,
                 const std::vector<int>& left,
                 const std::vector<int>& right) {
    int root = GetRoot(left, right);
    if (root < 0) {
        return false;
    }
    std::vector<bool> visited(n, false);
    std::queue<int> queue;
    queue.push(root);
    while (!queue.empty()) {
        int cur = queue.front();
        queue.pop();
        if (cur == -1) {
            continue;
        }
        if (visited[cur]) {
            return false;
        }
        visited[cur] = true;
        queue.push(left[cur]);
        queue.push(right[cur]);
    }
    return std::accumulate(visited.begin(), visited.end(), 0) == n;
}

using std::vector;

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        return ValidateBfs(n, leftChild, rightChild);
    }
};
