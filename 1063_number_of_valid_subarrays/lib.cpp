#include <vector>

int CountValidSubarrays(const std::vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    std::vector<int> subarray_start_candidates;
    for (int i = 0; i < n; ++i) {
        while (!subarray_start_candidates.empty()
               && nums[i] < nums[subarray_start_candidates.back()]) {
            count += i - subarray_start_candidates.back();
            subarray_start_candidates.pop_back();
        }
        subarray_start_candidates.push_back(i);
    }
    for (int array_start_idx : subarray_start_candidates) {
        count += n - array_start_idx;
    }
    return count;    
}

using std::vector;

class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        return CountValidSubarrays(nums);
    }
};
