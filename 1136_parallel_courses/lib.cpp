#include <algorithm>
#include <vector>

bool SetDepth(int from, const std::vector<std::vector<int>>& graph,
             std::vector<int>& depths, std::vector<bool>& in_path) {
    if (depths[from] != -1) {
        return true;
    }
    in_path[from] = true;
    int max_depth = 0;
    for (int next : graph[from]) {
        if (in_path[next]) {
            return false;
        }
        if (!SetDepth(next, graph, depths, in_path)) {
            return false;
        }
        if (depths[next] + 1 > max_depth) {
            max_depth = depths[next] + 1;
        }
    }
    in_path[from] = false;
    depths[from] = max_depth;
    return true;
}

int GetMaxDepth(int n, const std::vector<std::vector<int>>& relations) {
    std::vector<std::vector<int>> graph(n);
    for (auto& from_to : relations) {
        graph[from_to[0]].push_back(from_to[1]);
    }

    std::vector<bool> in_path(n, false);
    std::vector<int> depths(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!SetDepth(i, graph, depths, in_path)) {
            return -1;
        };
    }

    return *std::max_element(depths.begin(), depths.end());
}

using std::vector;

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        for (auto& relation : relations) {
            --relation[0];
            --relation[1];
        }
        int depth = GetMaxDepth(n, relations);
        return depth >= 0 ? depth + 1 : -1;
    }
};
