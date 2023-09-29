#include <vector>

long long GetIncreasingSubarraysCount(const std::vector<int>& nums) {
    int n = nums.size();
    long long count = 0;
    int begin = 0;
    for (int i = 1; i < n; ++i) {
        if (nums[i - 1] >= nums[i]) {
            long long len = i - begin;
            count += len * (len + 1) / 2;
            begin = i;
        }
    }
    long long len = n - begin;
    count += len * (len + 1) / 2;
    return count;
}

using std::vector;

class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        return GetIncreasingSubarraysCount(nums);
    }
};
