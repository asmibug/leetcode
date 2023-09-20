#include <algorithm>
#include <climits>
#include <vector>

int GetMinOperations(const std::vector<int>& nums, int x) {
    int n = nums.size();
    int min_operations = INT_MAX;

    int right = 0;
    while (right < n && x - nums[n - 1 - right] >= 0) {
        x -= nums[n - 1 - right];
        ++right;
    }
    if (x == 0) {
        min_operations = right;
    }
    for (int left = 0; left < n - right;) {
        x -= nums[left];
        ++left;
        while (right > 0 && x < 0) {
            --right;
            x += nums[n - 1 - right];
        }
        if (x == 0) {
            min_operations = std::min(left + right, min_operations);
        }
    }
    return min_operations != INT_MAX ? min_operations : -1;
}

using std::vector;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        return GetMinOperations(nums, x);
    }
};
