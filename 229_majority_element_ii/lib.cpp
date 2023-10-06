#include <climits>
#include <vector>

std::vector<int> GetMajorityElements(const std::vector<int>& nums) {
    constexpr int parts = 3;
    constexpr int sz = parts - 1;
    int vals[sz];
    for (int i = 0; i < sz; ++i) {
        vals[i] = INT_MIN;
    }
    int cnts[sz] = {0};
    for (int x : nums) {
        bool cell_found = false;
        for (int i = 0; i < sz; ++i) {
            if (vals[i] == x) {
                ++cnts[i];
                cell_found = true;
                break;
            }
        }
        if (cell_found) {
            continue;
        }
        for (int i = 0; i < sz; ++i) {
            if (cnts[i] == 0) {
                vals[i] = x;
                cnts[i] = 1;
                cell_found = true;
                break;
            }
        }
        if (cell_found) {
            continue;
        }
        for (int i = 0; i < sz; ++i) {
            --cnts[i];
        }
    }

    for (int i = 0; i < sz; ++i) {
        cnts[i] = 0;
    }
    for (int x : nums) {
        for (int i = 0; i < sz; ++i) {
            if (vals[i] == x) {
                ++cnts[i];
            }
        }
    }

    std::vector<int> res;
    for (int i = 0, n = nums.size(); i < sz; ++i) {
        if (cnts[i] > n / parts) {
            res.push_back(vals[i]);
        }
    }
    return res;
}

using std::vector;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        return GetMajorityElements(nums);
    }
};
