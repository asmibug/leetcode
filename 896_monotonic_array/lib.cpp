#include <vector>

bool IsMonotonic(const std::vector<int>& nums) {
    int n = nums.size();
    bool has_increasing = false;
    bool has_decreasing = false;
    for (int i = 1; i < n; ++i) {
        if (nums[i - 1] < nums[i]) {
            has_increasing = true;
        } else if (nums[i - 1] > nums[i]) {
            has_decreasing = true;
        }
        if (has_increasing && has_decreasing) {
            return false;
        }
    }
    return true;
}

using std::vector;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        return IsMonotonic(nums);
    }
};
