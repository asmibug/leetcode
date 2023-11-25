#include <algorithm>
#include <execution>
#include <numeric>
#include <vector>

/**
 * y_i = sum_j(|x_i - x_j|)
 * = sum_{j: j < i}(x_i - x_j) + sum_{j: j >= i}(x_j - x_i)
 * = i * x_i - (n - i) * x_i - sum_{j: j < i}(x_j) + sum_{j: j >= i}(x_j)
 * = sum_j(x_j) - 2 * sum_{j: j < i}(x_j) + (2 * i - n) * x_i
 * y_i - y_{i-1} = -2 * x_{i-1} + (2*i - n) * x_i - (2*(i-1) - n) * x_{i-1}
 * = (2*i - n) * (x_i - x_{i-1})
*/
std::vector<int> GetDifferencesSum(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> res;
    res.reserve(n);
    int base = std::reduce(std::execution::par, nums.begin(), nums.end());
    for (int i = 0; i < n; ++i) {
        res.push_back(base + (2 * i - n) * nums[i]);
        base -= 2 * nums[i];
    }
    return res;
}

using std::vector;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        return GetDifferencesSum(nums);
    }
};
