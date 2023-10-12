#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class MountainArray {
public:
    MountainArray(std::vector<int> array) : array_(std::move(array)) {
    }

    int get(int index) const {
        return array_[index];
    }

    int length() const {
        return array_.size();
    }
private:
    std::vector<int> array_;
};



int FindIdxMax(MountainArray& array) {
    static constexpr int base = 1e5;
    static const int partition = 0.5 * (3 - sqrt(5)) * base;

    int left = 0;
    int right = array.length() - 1;
    int left_candidate = left + (right - left) * partition / base;
    int right_candidate = left + (right + 1 - left) * (base - partition) / base;
    int left_value = array.get(left_candidate);
    int right_value = array.get(right_candidate);
    while (left < right) {
        if (left_value < right_value) {
            left = left_candidate + 1;
            left_candidate = right_candidate;
            left_value = right_value;
            right_candidate = (
                left + (right + 1 - left) * (base - partition) / base);
            right_value = array.get(right_candidate);
        } else {
            right = right_candidate;
            right_candidate = left_candidate;
            right_value = left_value;
            left_candidate = left + (right - left) * partition / base;
            left_value = array.get(left_candidate);
        }
    }
    return left;
}

template <typename Compare = std::less<int>>
int FindIdx(int target, MountainArray& array, int begin, int end,
            Compare cmp = Compare()) {
    while (begin < end) {
        int m = begin + (end - begin) / 2;
        if (cmp(array.get(m), target)) {
            begin = m + 1;
        } else {
            end = m;
        }
    }
    return begin;
}

int FindInMountainArray(int target, MountainArray& array) {
    int n = array.length();
    int max_idx = FindIdxMax(array);
    int idx = FindIdx(target, array, 0, max_idx);
    if (array.get(idx) == target) {
        return idx;
    }
    idx = FindIdx(target, array, max_idx + 1, n, std::greater<int>());
    if (idx < n && array.get(idx) == target) {
        return idx;
    }
    return -1;
}

int FindInMountainArray(int target, MountainArray&& array) {
    return FindInMountainArray(target, array);
}

using std::vector;

class Solution {
public:
    int findInMountainArray(int target, MountainArray& mountainArr) {
        return FindInMountainArray(target, mountainArr);
    }
};
