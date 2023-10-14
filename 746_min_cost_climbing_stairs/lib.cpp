#include <algorithm>
#include <vector>

int GetMinTotalCost(const std::vector<int>& costs) {
    int n = costs.size();
    int cost1 = costs.back();
    int cost2 = 0;
    for (int i = n - 2; i >= 0; --i) {
        cost2 = costs[i] + std::min(cost1, cost2);
        std::swap(cost1, cost2);
    }
    return std::min(cost1, cost2);
}

using std::vector;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return GetMinTotalCost(cost);    
    }
};
