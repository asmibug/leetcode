#include <algorithm>
#include <vector>

int GetMaxCoinsSort(std::vector<int>& piles) {
    std::ranges::sort(piles);
    int res = 0;
    for (unsigned i = piles.size() / 3; i < piles.size(); i += 2) {
        res += piles[i];
    }
    return res;
}

int GetMaxCoinsSort(std::vector<int>&& piles) {
    return GetMaxCoinsSort(piles);
}

int GetMaxCoinsCount(const std::vector<int>& piles) {
    constexpr int kMax = 1e4;
    int counts[kMax + 1] = {0};
    int max = 0;
    for (int p : piles) {
        ++counts[p];
        max = std::max(max, p);
    }
    int res = 0;
    int residue = 0;
    unsigned total_rounds = 0;
    while (true) {
        int rounds_played = (counts[max] + residue) / 2;
        residue = (counts[max] + residue) % 2;
        res += max * rounds_played;
        total_rounds += rounds_played;
        if (total_rounds >= piles.size() / 3) {
            break;
        }
        --max;
    }
    int extra_rounds = total_rounds - piles.size() / 3;
    return res - max * extra_rounds;
}

using std::vector;

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        return GetMaxCoinsCount(piles);
    }
};
