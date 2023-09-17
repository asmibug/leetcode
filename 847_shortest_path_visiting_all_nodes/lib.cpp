#include <vector>

int GetShortestPathLength(const std::vector<std::vector<int>>& graph) {
    int steps = 0;
    int all_visited = (1 << graph.size()) - 1;
    std::vector<std::vector<bool>> seen(all_visited + 1,
                                        std::vector<bool>(graph.size()));
    struct State {
        int visited;
        int current;
    };
    std::vector<State> queue;

    for (int i = 0; i - graph.size(); ++i) {
        seen[1 << i][i] = true;
        queue.push_back({1 << i, i});
    }

    while (!queue.empty()) {
        std::vector<State> next_queue;
        for (auto& state : queue) {
            if (state.visited == all_visited) {
                return steps;
            }
            for (int next : graph[state.current]) {
                int next_visited = state.visited | 1 << next;
                if (!seen[next_visited][next]) {
                    seen[next_visited][next] = true;
                    next_queue.push_back({next_visited, next});
                }
            }
        }
        ++steps;
        queue = std::move(next_queue);
    }

    return -1;
}

using std::vector;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        return GetShortestPathLength(graph);
    }
};
