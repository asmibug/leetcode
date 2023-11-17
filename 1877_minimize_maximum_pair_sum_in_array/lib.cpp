#include <algorithm>
#include <climits>
#include <vector>

int GetMinPairSumSort(std::vector<int>& nums) {
    int n = nums.size();
    std::ranges::sort(nums);
    int max_pair_sum = 0;
    for (int i = 0; i < n / 2; ++i) {
        max_pair_sum = std::max(max_pair_sum, nums[i] + nums[n - 1 - i]);
    }
    return max_pair_sum;
}

int GetMinPairSumSort(std::vector<int>&& nums) {
    return GetMinPairSumSort(nums);
}

int GetMinPairSumCount(const std::vector<int>& nums) {
    constexpr int kMaxNum = 1e5;
    static int counts[kMaxNum + 1] = {0};
    int min = INT_MAX;
    int max = INT_MIN;
    for (int x : nums) {
        ++counts[x];
        min = std::min(min, x);
        max = std::max(max, x);
    }
    int max_pair_sum = 0;
    for (int pairs_left = nums.size() / 2; pairs_left > 0; --pairs_left) {
        while (!counts[min]) {
            ++min;
        }
        --counts[min];
        while (!counts[max]) {
            --max;
        }
        --counts[max];
        max_pair_sum = std::max(max_pair_sum, min + max);
    }
    return max_pair_sum;
}

using std::vector;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        if (nums.size() < 1000) {
            return GetMinPairSumSort(nums);
        }
        return GetMinPairSumCount(nums);
    }
};
