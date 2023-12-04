/**
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * 
 * Approach: lower bound and upper bound binary search
*/

#include <functional>
#include <vector>

template<typename Compare = std::less<int>>
std::vector<int>::const_iterator BinSearch(
        std::vector<int>::const_iterator begin,
        std::vector<int>::const_iterator end,
        int target,
        Compare cmp = Compare()) {
    while (begin != end) {
        auto m = begin + (end - begin) / 2;
        if (cmp(*m, target)) {
            begin = m + 1;
        } else {
            end = m;
        }
    }
    return begin;
}

std::vector<int> GetBounds(const std::vector<int>& nums, int target) {
    auto it = BinSearch(nums.begin(), nums.end(), target);
    if (it == nums.end() || *it != target) {
        return {-1, -1};
    }
    std::vector<int> bounds;
    bounds.push_back(it - nums.begin());
    it = BinSearch(it, nums.end(), target, std::less_equal<int>());
    bounds.push_back(it - nums.begin() - 1);
    return bounds;
}

using std::vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return GetBounds(nums, target);
    }
};
