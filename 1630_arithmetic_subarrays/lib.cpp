#include <algorithm>
#include <climits>
#include <vector>

std::vector<bool> CheckArithmeticSubarraysBySort(const std::vector<int>& nums,
                                                 const std::vector<int>& l,
                                                 const std::vector<int>& r) {
    int m = l.size();
    std::vector<bool> res;
    for (int i = 0; i < m; ++i) {
        std::vector<int> subarray(nums.begin() + l[i], nums.begin() + r[i] + 1);
        std::ranges::sort(subarray);
        int step = subarray[0] - subarray[1];
        bool is_arithmetic = true;
        for (auto j = 1u; j + 1 < subarray.size() && is_arithmetic; ++j) {
            is_arithmetic = subarray[j] - subarray[j + 1] == step;
        }
        res.push_back(is_arithmetic);
    }
    return res;
}

std::vector<bool> CheckArithmeticSubarraysByVect(const std::vector<int>& nums,
                                                 const std::vector<int>& l,
                                                 const std::vector<int>& r) {
    int m = l.size();
    std::vector<bool> res;
    for (int i = 0; i < m; ++i) {
        if (r[i] - l[i] < 2) {
            res.push_back(true);
            continue;
        }
        auto it_pair = std::minmax_element(
            nums.begin() + l[i], nums.begin() + r[i] + 1);
        int min = *it_pair.first;
        int max = *it_pair.second;
        if (min == max) {
            res.push_back(true);
            continue;
        }
        int len = r[i] - l[i] + 1;
        if ((max - min) % (len - 1)) {
            res.push_back(false);
            continue;
        }

        int step = (max - min) / (len - 1);
        std::vector<bool> seen(len, false);
        int j = l[i];
        for (; j <= r[i]; ++j) {
            int diff = nums[j] - min;
            int idx = diff / step;
            if (diff % step || seen[idx]) {
                break;
            }
            seen[idx] = true;
        }
        res.push_back(j > r[i]);
    }
    return res;
}

std::vector<bool> CheckArithmeticSubarraysByPresort(
        const std::vector<int>& nums,
        const std::vector<int>& l,
        const std::vector<int>& r) {
    int n = nums.size();
    int m = l.size();
    std::vector<short> indices;
    for (int i = 0; i < n; ++i) {
        indices.push_back(i);
    }
    std::ranges::sort(indices,
                      [&nums](int i, int j){return nums[i] < nums[j];});
    
    std::vector<bool> res;
    for (int j = 0; j < m; ++j) {
        int prev = INT_MIN;
        int step = -1;
        bool is_arithmetic = true;
        for (int i = 0; i < n && is_arithmetic; ++i) {
            if (indices[i] < l[j] || indices[i] > r[j]) {
                continue;
            }
            if (prev == INT_MIN) {
            } else if (step == -1) {
                step = nums[indices[i]] - prev;
            } else {
                is_arithmetic = nums[indices[i]] - prev == step;
            }
            prev = nums[indices[i]];
        }
        res.push_back(is_arithmetic);
    }
    return res;
}

using std::vector;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(
            vector<int>& nums, vector<int>& l, vector<int>& r) {
        return CheckArithmeticSubarraysByVect(nums, l, r);
    }
};
