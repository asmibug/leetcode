#include <algorithm>
#include <vector>

constexpr int kMod = 1e9 + 7;

int GetNumWays(int steps, int idx, int len,
               std::vector<std::vector<int>>& memo) {
    if (idx < 0 || idx >= len) {
        return 0;
    }
    if (steps == 0) {
        if (idx == 0) {
            return 1;
        }
        return 0;
    }
    if (memo[steps - 1][idx] != -1) {
        return memo[steps - 1][idx];
    }

    int res = (GetNumWays(steps - 1, idx - 1, len, memo) + 0LL
               + GetNumWays(steps - 1, idx, len, memo)
               + GetNumWays(steps - 1, idx + 1, len, memo)
               ) % kMod;
    memo[steps - 1][idx] = res;
    return res;
}

int GetNumWaysRecursion(int steps, int len) {
    int effective_len = std::min(len, steps / 2 + 1);
    auto memo = std::vector(steps, std::vector(effective_len, -1));
    return GetNumWays(steps, 0, effective_len, memo);
}

int GetNumWaysIteration(int steps, int len) {
    int effective_len = std::min(len, steps / 2 + 1);
    auto num_ways = std::vector(effective_len + 2, 0);
    num_ways[1] = 1;
    auto num_ways_new = num_ways;
    for (int i = 0; i < steps; ++i) {
        for (int j = 1; j < effective_len + 1; ++j) {
            num_ways_new[j] = (num_ways[j - 1] + 0LL
                               + num_ways[j]
                               + num_ways[j + 1]
                               ) % kMod;
        }
        std::swap(num_ways, num_ways_new);
    }
    return num_ways[1];
}

class Solution {
public:
    int numWays(int steps, int arrLen) {
        return GetNumWaysIteration(steps, arrLen);    
    }
};
