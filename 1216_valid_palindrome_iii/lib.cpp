/**
 * Approach: find the max length of palindromic subsequence
 * Method: DP
 * DP approaches:
 * 1) Recursive (top-down)
 * 2) Iterative (bottom-up)
*/

#include <string>
#include <vector>

constexpr int kMaxLen = 1000;

int GetMaxPalindromicSubsequenceLen(const std::string& s, int l, int r,
                                    short memo[kMaxLen][kMaxLen]) {
    if (l > r) {
        return 0;
    }
    if (l == r) {
        return 1;
    }
    if (memo[l][r]) {
        return memo[l][r] - 1;
    }
    if (s[l] == s[r]) {
        memo[l][r] = 3 + GetMaxPalindromicSubsequenceLen(s, l + 1, r - 1, memo);
        return memo[l][r] - 1;
    }
    memo[l][r] = 1 + std::max(
        GetMaxPalindromicSubsequenceLen(s, l + 1, r, memo),
        GetMaxPalindromicSubsequenceLen(s, l, r - 1, memo));
    return memo[l][r] - 1;
}

bool IsValidPalindromeRecursive(const std::string& s, int k) {
    int n = s.size();
    short memo[kMaxLen][kMaxLen] = {0};
    return n - k <= GetMaxPalindromicSubsequenceLen(
        s, 0, s.size() - 1, memo);
}

static short memo[kMaxLen];

bool IsValidPalindromeIterative(const std::string& s, int k) {
    int n = s.size();
    std::fill(memo, memo + n, 0);
    for (int i = n - 1; i >= 0; --i) {
        int prev = memo[i];
        memo[i] = 1;
        for (int j = i + 1; j < n; ++j) {
            int prev_to_save = memo[j];
            if (s[i] == s[j]) {
                memo[j] = 2 + prev;
            } else {
                memo[j] = std::max(memo[j], memo[j - 1]);
            }
            prev = prev_to_save;
        }
    }
    return memo[n - 1] >= n - k;
}

using std::string;

class Solution {
public:
    bool isValidPalindrome(const string& s, int k) {
        return IsValidPalindromeIterative(s, k);
    }
};
