#include <climits>  // INT_MAX
#include <vector>  // std::vector
#include <unordered_map>  // std::unordered_map

int GetCombinationsNumRecursion(const std::vector<int>& nums, int target,
                                std::unordered_map<int, int>& memo) {
    if (memo.contains(target)) {
        return memo[target];
    }
    int count = 0;
    for (int n : nums) {
        if (n == target) {
            ++count;
        } else if (n < target) {
            count += GetCombinationsNumRecursion(nums, target - n, memo);
        }
    }
    memo[target] = count;
    return count;
}

int GetCombinationsNumRecursive(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> memo;
    return GetCombinationsNumRecursion(nums, target, memo);
}

int GetCombinationsNumIterative(const std::vector<int>& nums, int target) {
    std::vector<int> counts = {1};
    for (int x = 1; x <= target; ++x) {
        int count = 0;
        for (int n : nums) {
            if (x - n >= 0) {
                if (counts[x - n] >= INT_MAX - count) {
                    count = INT_MAX;
                    break;
                }
                count += counts[x - n];
            }
        }
        counts.push_back(count);
    }
    return counts[target];
}

using std::vector;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        return GetCombinationsNumIterative(nums, target);
    }
};
