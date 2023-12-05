/**
 * https://leetcode.com/problems/two-sum-less-than-k/
 * 
 * Approaches:
 * 0) Brute-force: check all pairs for O(n^2)
 * 1) Use tree-set with descending order to get the upper bound of diff
 * 2) Sort and use binary search to find the upper bound
 * 3) Sort and use two pointers such that sum is always less than k
 * 4) Use counting sort and two pointers
 * 
 * Counting sort optimizations:
 * 1) Instead of counts store bool
*/

#include <algorithm>
#include <functional>
#include <set>
#include <vector>

int GetMaxSumByMap(const std::vector<int>& nums, int k) {
    int max_sum = -1;
    std::set<int, std::greater<int>> seen;
    for (int x : nums) {
        auto it = seen.upper_bound(k - x);
        if (it != seen.end()) {
            max_sum = std::max(max_sum, x + *it);
            if (max_sum == k - 1) {
                break;
            }
        }
        seen.insert(x);
    }
    return max_sum;
}

int GetMaxSumBySortBinSearch(std::vector<int>& nums, int k) {
    std::sort(nums.rbegin(), nums.rend());
    int max_sum = -1;
    for (auto it1 = nums.begin(); it1 + 1 < nums.end(); ++it1) {
        auto it2 = std::upper_bound(
            it1 + 1, nums.end(), k - *it1, std::greater());
        if (it2 != nums.end()) {
            max_sum = std::max(max_sum, *it1 + *it2);
            if (max_sum == k - 1) {
                break;
            }
        }
    }
    return max_sum;
}

int GetMaxSumBySortBinSearch(std::vector<int>&& nums, int k) {
    return GetMaxSumBySortBinSearch(nums, k);
}

int GetMaxSumBySortTwoPointers(std::vector<int>& nums, int k) {
    std::ranges::sort(nums);
    int max_sum = -1;
    auto it2 = nums.end() - 1;
    for (auto it1 = nums.begin(); it1 < it2; ++it1) {
        while (it1 != it2 && *it1 + *it2 >= k) {
            --it2;
        }
        if (it1 != it2) {
            max_sum = std::max(max_sum, *it1 + *it2);
        }
    }
    return max_sum;
}

int GetMaxSumBySortTwoPointers(std::vector<int>&& nums, int k) {
    return GetMaxSumBySortTwoPointers(nums, k);
}

int GetMaxSumByCounting(std::vector<int>& nums, int k) {
    constexpr int kMaxNum = 1000;
    unsigned char counts[kMaxNum + 1] = {0};
    int min = kMaxNum;
    int max = 0;
    for (int x : nums) {
        ++counts[x];
        min = std::min(min, x);
        max = std::max(max, x);
    }
    int max_sum = -1;
    while (min < max) {
        if (min + max < k) {
            max_sum = std::max(max_sum, min + max);
            do {
                ++min;
            } while (counts[min] == 0);
        } else {
            do {
                --max;
            } while (counts[max] == 0);
        }
    }
    if (min == max && counts[min] > 1 && min + max < k) {
        max_sum = std::max(max_sum, min + max);
    }
    return max_sum;
}

int GetMaxSumByCounting(std::vector<int>&& nums, int k) {
    return GetMaxSumByCounting(nums, k);
}

int GetMaxSumByBucket(std::vector<int>& nums, int k) {
    constexpr int kMaxNum = 1000;
    std::vector<bool> seen(kMaxNum + 1, false);
    int max_sum = -1;
    for (int x : nums) {
        if (seen[x] && 2 * x < k) {
            max_sum = std::max(max_sum, 2 * x);
        }
        seen[x] = true;
    }
    int left = 0;
    int right = std::min(kMaxNum, k - 1);
    while (left < right) {
        if (!seen[left]) {
            ++left;
            continue;
        }
        if (!seen[right]) {
            --right;
            continue;
        }
        if (left + right < k) {
            max_sum = std::max(max_sum, left + right);
            ++left;
        } else {
            --right;
        }
    }
    return max_sum;
}

int GetMaxSumByBucket(std::vector<int>&& nums, int k) {
    return GetMaxSumByBucket(nums, k);
}

using std::vector;

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        return GetMaxSumByBucket(nums, k);
    }
};
