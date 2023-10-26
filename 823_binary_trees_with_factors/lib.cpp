#include <algorithm>
#include <unordered_map>
#include <vector>

static constexpr int kMod = 1e9 + 7;

int GetNumFactoredBinaryTreesSimple(std::vector<int>& factors) {
    std::ranges::sort(factors);
    std::unordered_map<int, int> counts;
    int res = 0;
    for (int factor: factors) {
        auto count = 1LL;
        for (auto [first, first_count] : counts) {
            if (factor % first == 0 && counts.contains(factor / first)) {
                count += 1LL * first_count * counts[factor / first];
            }
        }
        counts[factor] = count % kMod;
        res = (res + count) % kMod;
    }
    return res;
}

int GetNumFactoredBinaryTreesSimple(std::vector<int>&& factors) {
    return GetNumFactoredBinaryTreesSimple(factors);
}

int GetNumFactoredBinaryTreesOptimized(std::vector<int>& factors) {
    int n = factors.size();
    std::ranges::sort(factors);
    std::unordered_map<int, int> counts;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int factor = factors[i];
        auto count = 1LL;
        int j = 0;
        for (; 1LL * factors[j] * factors[j] < factor; ++j) {
            int first = factors[j];
            int first_count = counts[first];
            if (factor % first == 0 && counts.contains(factor / first)) {
                count += 2LL * first_count * counts[factor / first];
            }
        }
        if (1LL * factors[j] * factors[j] == factor) {
            count += 1LL * counts[factors[j]] * counts[factors[j]];
        }
        counts[factor] = count % kMod;
        res = (res + count) % kMod;
    }
    return res;
}

int GetNumFactoredBinaryTreesOptimized(std::vector<int>&& factors) {
    return GetNumFactoredBinaryTreesOptimized(factors);
}

using std::vector;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        return GetNumFactoredBinaryTreesOptimized(arr);
    }
};
