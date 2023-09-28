#include <algorithm>
#include <vector>

std::vector<int> SortByParity(std::vector<int>& nums) {
    int n = nums.size();
    int idx_of_next_even = 0;
    for (int i = 0; i < n; ++i) {
        if (nums[i] % 2 == 0) {
            std::swap(nums[idx_of_next_even], nums[i]);
            ++idx_of_next_even;
        }
    }
    return nums;
}

std::vector<int> SortByParity(std::vector<int>&& nums) {
    return SortByParity(nums);
}

using std::vector;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        return SortByParity(nums);
    }
};
