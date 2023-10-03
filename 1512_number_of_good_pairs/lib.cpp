#include <vector>

constexpr int kMaxNum = 100;

int GetIdenticalPairsNum(const std::vector<int>& nums) {
    unsigned char counts[kMaxNum + 1] = {};
    for (int num : nums) {
        ++counts[num];
    }
    int total_count = 0;
    for (int c : counts) {
        total_count += c * (c - 1) / 2;
    }
    return total_count;
}

using std::vector;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        return GetIdenticalPairsNum(nums);
    }
};
