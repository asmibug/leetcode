#include <algorithm>
#include <climits>
#include <unordered_map>
#include <vector>

template <typename Memo>
int GetMinCostRecursive(int paid_wall_max_idx, int walls_left,
                        const std::vector<int>& cost,
                        const std::vector<int>& time,
                        Memo& memo) {
    if (walls_left <= 0) {
        return 0;
    }
    if (paid_wall_max_idx < 0) {
        return INT_MAX;
    }
    if (memo[paid_wall_max_idx][walls_left]) {
        return memo[paid_wall_max_idx][walls_left];
    }
    int cost_if_paint_current = GetMinCostRecursive(
        paid_wall_max_idx - 1, walls_left - 1 - time[paid_wall_max_idx],
        cost, time, memo);
    int cost_if_dont_paint_current = GetMinCostRecursive(
        paid_wall_max_idx - 1, walls_left,
        cost, time, memo
    ) - cost[paid_wall_max_idx];
    int res = cost[paid_wall_max_idx] + std::min(cost_if_dont_paint_current,
                                                 cost_if_paint_current);
    memo[paid_wall_max_idx][walls_left] = res;
    return res;
}

int GetMinCostRecursiveHash(const std::vector<int>& cost,
                            const std::vector<int>& time) {
    auto memo = std::vector(cost.size(), std::unordered_map<int, int>());
    return GetMinCostRecursive(cost.size() - 1, cost.size(), cost, time, memo);
}

int GetMinCostRecursiveVector(const std::vector<int>& cost,
                              const std::vector<int>& time) {
    auto memo = std::vector(cost.size(), std::vector(cost.size() + 1, 0));
    return GetMinCostRecursive(cost.size() - 1, cost.size(), cost, time, memo);
}

int GetMinCostIterative(const std::vector<int>& cost,
                        const std::vector<int>& time) {
    int n = cost.size();
    std::vector<int> min_costs(n + 1, INT_MAX);
    min_costs[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = n; j > 0; --j) {
            int cost_if_paint = min_costs[std::max(j - time[i] - 1, 0)];
            int cost_if_no_paint = min_costs[j] - cost[i];
            min_costs[j] = cost[i] + std::min(cost_if_paint, cost_if_no_paint);
        }
    }
    return min_costs[n];
}

using std::vector;

class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        return GetMinCostIterative(cost, time);
    }
};
