#include <algorithm>
#include <climits>
#include <vector>

int GetMaxDotProduct(const std::vector<int>& nums1,
                     const std::vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    std::vector<int> max_prod(n2 + 1, 0);
    auto new_max_prod = max_prod;
    int total_max = INT_MIN;
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            int candidate = nums1[i] * nums2[j] + max_prod[j];
            if (candidate > total_max) {
                total_max = candidate;
            }
            new_max_prod[j + 1] = std::max(
                {candidate, max_prod[j + 1], new_max_prod[j]});
        }
        std::swap(max_prod, new_max_prod);
    }
    return total_max;
}

using std::vector;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        return GetMaxDotProduct(nums1, nums2);
    }
};
