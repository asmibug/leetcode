#include <vector>
#include <unordered_map>

constexpr int kMod = 1e9 + 7;

int GetRev(int x) {
    int res = 0;
    for (; x; x /= 10) {
        res = res * 10 + x % 10;
    }
    return res;
}

int CountNicePairsHash(const std::vector<int>& nums) {
    std::unordered_map<int, int> counts;
    for (int x : nums) {
        ++counts[x - GetRev(x)];
    }
    auto total_count = 0LL;
    for (auto [_, count] : counts) {
        total_count += (count - 1LL) * count / 2;
    }
    return total_count % kMod;
}

using std::vector;

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        return CountNicePairsHash(nums);
    }
};
