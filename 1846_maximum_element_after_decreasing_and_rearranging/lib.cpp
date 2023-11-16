#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <vector>

int GetMaxStepsSort(std::vector<int>& arr) {
    std::ranges::sort(arr);
    int steps = 0;
    for (int x : arr) {
        steps = std::min(steps + 1, x);
    }
    return steps;
}

int GetMaxStepsSort(std::vector<int>&& arr) {
    return GetMaxStepsSort(arr);
}

int GetMaxStepsCount(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector counts(n + 1, 0);
    for (int x : arr) {
        ++counts[std::min(x, n)];
    }
    int steps = 0;
    for (int i = 1; i <= n; ++i) {
        steps = std::min(steps + counts[i], i);
    }
    return steps;
}

using std::vector;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        return GetMaxStepsSort(arr);
    }
};
