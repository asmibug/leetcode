#include <algorithm>
#include <vector>

namespace {
    int PreprocessSortUnique(std::vector<int>& nums) {
        int original_n = nums.size();
        std::sort(nums.begin(), nums.end());
        nums.resize(std::unique(nums.begin(), nums.end()) - nums.begin());
        return original_n;
    }

    int GetMinOperationsBinSearch(const std::vector<int>& nums, int original_n) {
        int min_deletions = nums.size();
        for (int del_left = 0; del_left < min_deletions; ++del_left) {
            auto it = std::lower_bound(nums.begin() + del_left, nums.end(),
                                       nums[del_left] + original_n);
            int del_right = nums.end() - it;
            min_deletions = std::min(min_deletions, del_left + del_right);
        }
        return min_deletions;
    }

    int GetMinOperationsSlidingWindow(const std::vector<int>& nums,
                                      int original_n) {
        auto right = std::lower_bound(nums.begin(), nums.end(),
                                      nums[0] + original_n);
        int min_deletions = nums.size();
        for (int del_left = 0; del_left < min_deletions; ++del_left) {
            while (right != nums.end()
                   && *right < nums[del_left] + original_n) {
                ++right;
            }
            int del_right = nums.end() - right;
            min_deletions = std::min(min_deletions, del_left + del_right);
        }
        return min_deletions;
    }

    int GetMinOperationsSlidingWindowMonotonous(const std::vector<int>& nums,
                                                int original_n) {
        int del_left = 0;
        int del_right = nums.size();
        for (; del_right > 0; --del_right) {
            if (nums[del_left] + original_n <= nums[nums.size() - del_right]) {
                ++del_left;
            }
        }
        return del_left;
    }
}

int GetMinOperations(std::vector<int>& nums) {
    int original_n = PreprocessSortUnique(nums);
    int n = nums.size();
    int deleted_duplicates = original_n - n;
    int min_deletions = GetMinOperationsSlidingWindowMonotonous(nums,
                                                                original_n);
    return deleted_duplicates + min_deletions;
}

int GetMinOperations(std::vector<int>&& nums) {
    return GetMinOperations(nums);
}

using std::vector;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        return GetMinOperations(nums);
    }
};
