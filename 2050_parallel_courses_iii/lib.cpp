#include <algorithm>
#include <vector>

std::vector<std::vector<int>> GetGraph(
        int n, const std::vector<std::vector<int>>& relations) {
    auto graph = std::vector(n + 1, std::vector(0, 0));
    for (int i = 1; i <= n; ++i) {
        graph[0].push_back(i);
    }
    for (const auto& edge : relations) {
        graph[edge[0]].push_back(edge[1]);
    }
    return graph;
}

int GetTimeAfter(int vertex,
        const std::vector<std::vector<int>>& graph,
        const std::vector<int>& times,
        std::vector<int>& next_times) {
    if (next_times[vertex] >= 0) {
        return next_times[vertex];
    }

    int max_next_time = 0;
    for (int next : graph[vertex]) {
        int time = (times[next - 1]
                    + GetTimeAfter(next, graph, times, next_times));
        if (time > max_next_time) {
            max_next_time = time;
        }
    }
    next_times[vertex] = max_next_time;
    return max_next_time;
}

int GetMinTimeDfs(int n,
                  const std::vector<std::vector<int>>& relations,
                  const std::vector<int>& times) {
    auto graph = GetGraph(n, relations);
    auto next_times = std::vector(n + 1, -1);
    return GetTimeAfter(0, graph, times, next_times);
}

int GetMinTimeKahn(int n,
                   const std::vector<std::vector<int>>& relations,
                   const std::vector<int>& times) {
    auto graph = GetGraph(n, relations);
    std::vector<int> inorders(n + 1, 0);
    for (const auto& children : graph) {
        for (int child : children) {
            ++inorders[child];
        }
    }
    std::vector<int> max_times(n + 1, 0);
    std::vector<int> queue = {0};
    while (!queue.empty()) {
        auto cur = queue.back();
        queue.pop_back();
        for (int next : graph[cur]) {
            --inorders[next];
            if (inorders[next] == 0) {
                queue.push_back(next);
            }
            max_times[next] = std::max(max_times[next],
                                       max_times[cur] + times[next - 1]);
        }
    }
    return *std::max_element(max_times.begin(), max_times.end());
}

using std::vector;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        return GetMinTimeKahn(n, relations, time);
    }
};
