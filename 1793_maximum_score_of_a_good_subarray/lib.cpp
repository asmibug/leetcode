#include <algorithm>
#include <vector>

int GetMaxScore(const std::vector<int>& nums, int k) {
    int n = nums.size();
    int max_score = nums[k];
    int cur_min = nums[k];
    int l = k - 1;
    int r = k + 1;
    while (l >= 0 && r < n) {
        cur_min = std::min(cur_min, std::max(nums[l], nums[r]));
        while (l >= 0 && nums[l] >= cur_min) {
            --l;
        }
        while (r < n && nums[r] >= cur_min) {
            ++r;
        }
        max_score = std::max(max_score, cur_min * (r - l - 1));
    }
    for (; l >= 0; --l) {
        if (nums[l] < cur_min) {
            max_score = std::max(max_score, cur_min * (r - l - 1));
            cur_min = nums[l];
        }
        --l;
    }
    for (; r < n; ++r) {
        if (nums[r] < cur_min) {
            max_score = std::max(max_score, cur_min * (r - l - 1));
            cur_min = nums[r];
        }
    }
    max_score = std::max(max_score, cur_min * (r - l - 1));
    return max_score;
}

using std::vector;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        return GetMaxScore(nums, k);        
    }
};
