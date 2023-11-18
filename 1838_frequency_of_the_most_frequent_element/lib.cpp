#include <algorithm>
#include <vector>

int GetMaxWindowSort(std::vector<int>& nums, int k) {
    int n = nums.size();
    std::ranges::sort(nums);
    int begin = 0;
    auto diff_sum = 0LL;
    for (int i = 1; i < n; ++i) {
        diff_sum += 1LL * (nums[i] - nums[i - 1]) * (i - begin);
        if (diff_sum > k) {
            diff_sum -= nums[i] - nums[begin];
            ++begin;
        }
    }
    return n - begin;
}

int GetMaxWindowSort(std::vector<int>&& nums, int k) {
    return GetMaxWindowSort(nums, k);
}

int GetMaxWindowCount(const std::vector<int>& nums, int k) {
    constexpr int kMaxValue = 1e5;
    static int counts[kMaxValue + 1] = {0};

    int min = kMaxValue;
    int max = 0;
    for (int x : nums) {
        ++counts[x];
        min = std::min(min, x);
        max = std::max(max, x);
    }

    int left = min;
    auto sum = 0LL;
    int count = 0;
    for (long long right = left; right <= max; ++right) {
        if (!counts[right]) {
            continue;
        }
        for (int i = 0; i < counts[right]; ++i) {
            sum += right;
            ++count;
            if (right * count - sum > k) {
                sum -= left;
                --count;
                --counts[left];
                while (!counts[left]) {
                    ++left;
                }
            }
        }
    }
    std::fill(&counts[left], &counts[max + 1], 0);
    return count;
}

using std::vector;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        return GetMaxWindowCount(nums, k);
    }
};
