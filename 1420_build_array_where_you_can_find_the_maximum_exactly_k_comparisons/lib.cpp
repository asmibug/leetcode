#include <algorithm>
#include <vector>

constexpr int kMod = 1'000'000'007;

int GetNumberExactMax(int n, int m, int k,
                      std::vector<std::vector<std::vector<int>>>& memo) {
    if (n < k || k == 0) {
        return 0;
    }
    if (n == 1 && k == 1) {
        return 1;
    }

    if (memo[n][m][k] != -1) {
        return memo[n][m][k];
    }
    int res = 1LL * m * GetNumberExactMax(n - 1, m, k, memo) % kMod;
    for (int i = 1; i <= m - 1; ++i) {
        res = (res + GetNumberExactMax(n - 1, i, k - 1, memo)) % kMod;
    }
    memo[n][m][k] = res;
    return res;
}

int GetNumberRecursive(int n, int m, int k) {
    std::vector<std::vector<std::vector<int>>> memo(
        n + 1, std::vector<std::vector<int>>(
            m + 1, std::vector<int>(
                k + 1, -1)));
    int res = 0;
    for (int i = 1; i <= m; ++i) {
        res = (res + GetNumberExactMax(n, i, k, memo)) % kMod;
    }
    return res;
}

int GetNumberIterative(int n, int m, int k) {
    std::vector<std::vector<int>> counts(m + 1, std::vector<int>(k + 1, 0));
    for (int i = 1; i <= m; ++i) {
        counts[i][1] = 1;
    }
    std::vector<std::vector<int>> prefix_sum(m + 1, std::vector<int>(k + 1, 0));
    auto new_counts = counts;
    for (int l = 2; l <= n; ++l) {
        std::vector<int> prefix_sum(k + 1, 0);
        auto new_prefix_sum = prefix_sum;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= std::min(k, l); ++j) {
                new_prefix_sum[j] = (prefix_sum[j]
                                     + counts[i - 1][j - 1]) % kMod;
                new_counts[i][j] = (1LL * i * counts[i][j]
                                    + new_prefix_sum[j]) % kMod;
            }
            std::swap(prefix_sum, new_prefix_sum);
        }
        std::swap(counts, new_counts);
    }
    int res = 0;
    for (int i = 1; i <= m; ++i) {
        res = (res + counts[i][k]) % kMod;
    }
    return res;
}

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        return GetNumberIterative(n, m, k);
    }
};
