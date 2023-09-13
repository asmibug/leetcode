#include <algorithm>  // std::max
#include <vector>  // std::vector

std::vector<int> GetCosts(const std::vector<int>& ratings) {
    std::vector<int> costs;
    costs.reserve(ratings.size());
    costs.push_back(1);
    for (unsigned i = 1; i < ratings.size(); ++i) {
        int cost = 1;
        if (ratings[i] > ratings[i - 1]) {
            cost = costs[i - 1] + 1;
        }
        costs.push_back(cost);
    }
    for (unsigned i = ratings.size() - 1; i > 0; --i) {
        if (ratings[i - 1] > ratings[i]) {
            costs[i - 1] = std::max(costs[i] + 1, costs[i - 1]);
        }
    }
    return costs;
}

int GetMinSumOfCandies(const std::vector<int>& ratings) {
    auto costs = GetCosts(ratings);
    int sum = 0;
    for (int c : costs) {
        sum += c;
    }
    return sum;
}

int GetMinSumOfCandiesOnePass(const std::vector<int>& ratings) {
    int n = ratings.size();
    int sum = 0;
    int current_min_idx = 0;
    for (int i = 0; i < n; ++i) {
        if (i != current_min_idx) {
            sum -= 1;
        }
        while (i + 1 < n && ratings[i + 1] > ratings[i]) {
            ++i;
        }
        int max_idx = i;
        while (i + 1 < n && ratings[i + 1] < ratings[i]) {
            ++i;
        }
        int min_idx = i;
        int range_left = max_idx - current_min_idx;
        int range_right = min_idx - max_idx;
        sum += (range_left * (range_left + 1) / 2
                + range_right * (range_right + 1) / 2
                + std::max(range_left, range_right) + 1);
        current_min_idx = min_idx;
        if (min_idx + 1 < n && ratings[min_idx] == ratings[min_idx + 1]) {
            ++current_min_idx;
        }
    }
    return sum;
}

using std::vector;

class Solution {
public:
    int candy(vector<int>& ratings) {
        return GetMinSumOfCandiesOnePass(ratings);
    }
};
