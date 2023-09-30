#include <algorithm>
#include <climits>
#include <functional>
#include <map>
#include <vector>

bool IsInIntervals(int x,
                   const std::map<int, int, std::greater<int>>& intervals) {
    auto candidate = intervals.upper_bound(x);
    return candidate != intervals.end() && candidate->second > x;
}

void MergeIntervals(
    std::map<int, int, std::greater<int>>& intervals,
    int left, int right
) {
    auto candidate = intervals.upper_bound(right);
    while (candidate->first > left) {
        intervals.erase(candidate);
        candidate = intervals.upper_bound(right);
    }
}

bool Has132PatternIntervals(const std::vector<int>& nums) {
    int current_min = INT_MAX;
    std::map<int, int, std::greater<int>> intervals;
    for (int x : nums) {
        if (IsInIntervals(x, intervals)) {
            return true;
        }
        if (x <= current_min) {
            current_min = x;
        } else {
            intervals[current_min] = x;
            MergeIntervals(intervals, current_min, x);
        }
    }
    return false;
}

bool Has132PatternMinStack(const std::vector<int>& nums) {
    int n = nums.size();

    std::vector<int> mins = {nums[0]};
    mins.reserve(nums.size());
    for (int i = 1; i < n; ++i) {
        mins.push_back(std::min(mins[i - 1], nums[i]));
    }

    std::vector<int> third_candidates;  // invariant: sorted decreasing
    for (int i = n - 1; i > 0; --i) {
        if (nums[i] <= mins[i]) {
            continue;
        }
        // mins[i] < nums[i], so nums[i] is the candidate for second
        while (!third_candidates.empty()
               && third_candidates.back() <= mins[i]) {
            third_candidates.pop_back();
        }
        // either third_candidates.empty() or third_candidates.back() > mins[i]
        if (!third_candidates.empty() && third_candidates.back() < nums[i]) {
            return true;
        }
        // either third_candidates.empty()
        // or third_candidates.back() >= nums[i]
        // so we keep invariant that third_candidates is sorted decreasing
        third_candidates.push_back(nums[i]);
    }

    return false;
}

bool Has132PatternStack(const std::vector<int>& nums) {
    int third = INT_MIN;
    std::vector<int> third_candidates;
    for (auto it = nums.rbegin(); it != nums.rend(); ++it) {
        if (*it < third) {
            return true;
        }
        while (!third_candidates.empty() && third_candidates.back() < *it) {
            third = third_candidates.back();
            third_candidates.pop_back();
        }
        if (*it > third) {
            third_candidates.push_back(*it);
        }
    }
    return false;
}

using std::vector;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        return Has132PatternStack(nums);
    }
};
