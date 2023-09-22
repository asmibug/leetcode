#include <algorithm>
#include <vector>

int GetNext(unsigned& idx1,
            unsigned& idx2,
            const std::vector<int>& nums1,
            const std::vector<int>& nums2) {
    if (idx1 >= nums1.size()) {
        return nums2[idx2++];
    }
    if (idx2 >= nums2.size()) {
        return nums1[idx1++];
    }
    if (nums1[idx1] < nums2[idx2]) {
        return nums1[idx1++];
    }
    return nums2[idx2++];
}

double FindMedianSortedArraysMerge(const std::vector<int>& nums1,
                                   const std::vector<int>& nums2) {
    int mn = nums1.size() + nums2.size();
    unsigned idx1 = 0;
    unsigned idx2 = 0;
    for (int i = 0; i < (mn - 1) / 2; ++i) {
        GetNext(idx1, idx2, nums1, nums2);
    }
    if (mn % 2 == 0) {
        return (GetNext(idx1, idx2, nums1, nums2)
                + GetNext(idx1, idx2, nums1, nums2)
               ) / 2.;
    }
    return GetNext(idx1, idx2, nums1, nums2);
}


int FindKthElement(int k,
                   int nums1_begin,
                   int nums1_end,
                   int nums2_begin,
                   int nums2_end,
                   const std::vector<int>* nums1,
                   const std::vector<int>* nums2) {
    if (nums1_begin >= nums1_end) {
        return (*nums2)[k + nums2_begin];
    }
    if (nums2_begin >= nums2_end) {
        return (*nums1)[k + nums1_begin];
    }
    int nums1_mid = (nums1_begin + nums1_end) / 2;
    int nums2_mid = (nums2_begin + nums2_end) / 2;
    if ((*nums1)[nums1_mid] > (*nums2)[nums2_mid]) {
        std::swap(nums1, nums2);
        std::swap(nums1_begin, nums2_begin);
        std::swap(nums1_end, nums2_end);
        std::swap(nums1_mid, nums2_mid);
    }
    int len1 = nums1_mid - nums1_begin;
    int len2 = nums2_mid - nums2_begin;
    if (k <= len1 + len2) {
        return FindKthElement(
            k, nums1_begin, nums1_end, nums2_begin, nums2_mid,
            nums1, nums2);
    } else {
        return FindKthElement(
            k - len1 - 1, nums1_mid + 1, nums1_end, nums2_begin, nums2_end,
            nums1, nums2);
    }
}

double FindMedianSortedArrayRecursive(const std::vector<int>& nums1,
                                      const std::vector<int>& nums2) {
    int mn = nums1.size() + nums2.size();
    if (mn % 2 == 0) {
        return (
            FindKthElement(
                mn / 2 - 1, 0, nums1.size(), 0, nums2.size(), &nums1, &nums2)
            + FindKthElement(
                mn / 2, 0, nums1.size(), 0, nums2.size(), &nums1, &nums2)
        ) / 2.;
    }
    return FindKthElement(
        mn / 2, 0, nums1.size(), 0, nums2.size(), &nums1, &nums2);
}

using std::vector;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return FindMedianSortedArraysMerge(nums1, nums2);
    }
};
