/**
 * https://leetcode.com/problems/next-greater-element-i/
 * 
 * There are 2 tasks here:
 * 1. For each number in nums1 find index of the number in nums2
 * 2. For each number in nums2 find the next greater element
 * 
 * Task 1 approaches:
 * 1) Brute-force: for each element in nums1 find it in nums2 for O(n^2)
 * 2.1) Hash-map each element in nums1 to its index in nums1 for O(n)
 * 2.2) Or hash-map each element in nums2 to its index (less convenient)
 * 3) Instead of hash-map we can use an array for the same purpose
 * 
 * Task 2 approaches:
 * 1) Brute-force find next greater for O(n^2)
 * 2) Use monotonic stack (non-increasing) going forward
 * 2.1) We can use monotonic stack when walking backwards too (less convenient)
 * 3) We can go backwards and for each element store the next greatest in the
 *    hash-map. This solution has O(n) complexity, because when looking for the
 *    next greatest element we pass through each element only once.
*/

#include <ranges>
#include <unordered_map>
#include <vector>

std::vector<int> GetGreaterElementsIndicesByStack(
        const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::unordered_map<int, int> num2idx;
    for (unsigned i = 0; i < nums1.size(); ++i) {
        num2idx[nums1[i]] = i;
    }

    std::vector<int> res(nums1.size(), -1);
    std::vector<int> prev_nonincreasing;
    for (int x : nums2) {
        while (!prev_nonincreasing.empty() && x > prev_nonincreasing.back()) {
            int prev = prev_nonincreasing.back();
            if (num2idx.contains(prev)) {
                res[num2idx[prev]] = x;
            }
            prev_nonincreasing.pop_back();
        }
        prev_nonincreasing.push_back(x);
    }
    return res;
}

std::vector<int> GetGreaterElementsIndicesByMap(
        const std::vector<int>& nums1, const std::vector<int>& nums2) {
    constexpr int kMaxNum = 1e4;
    short next_greater[kMaxNum + 1] = {0};
    int prev = -1;
    for (int x : nums2 | std::views::reverse) {
        while (prev != -1 && prev <= x) {
            prev = next_greater[prev];
        }
        next_greater[x] = prev;
        prev = x;
    }

    std::vector<int> res;
    for (int x : nums1) {
        res.push_back(next_greater[x]);
    }
    return res;
}

using std::vector;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        return GetGreaterElementsIndicesByMap(nums1, nums2);
    }
};
