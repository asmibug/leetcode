#include <cstdint>
#include <vector>

int GetReductionsNum(const std::vector<int>& nums) {
    constexpr int kMaxValue = 5e4;
    uint16_t counts[kMaxValue + 1] = {0};
    for (int x : nums) {
        ++counts[x];
    }

    int reductions_num = 0;
    int steps = 0;
    for (int x = 0; x <= kMaxValue; ++x) {
        reductions_num += counts[x] * steps;
        steps += static_cast<bool>(counts[x]);
    }
    return reductions_num;
}

using std::vector;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        return GetReductionsNum(nums);
    }
};
