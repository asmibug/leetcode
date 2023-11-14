#include <algorithm>
#include <bitset>
#include <climits>
#include <string>

int CountPalindromicSubsequenceSet(const std::string& s) {
    constexpr int num_letters = 'z' - 'a' + 1;
    int n = s.size();

    int min_idx[num_letters];
    std::fill(min_idx, min_idx + num_letters, INT_MAX);
    int max_idx[num_letters];
    for (int i = 0; i < n; ++i) {
        int j = s[i] - 'a';
        min_idx[j] = std::min(min_idx[j], i);
        max_idx[j] = i;
    }
    int count = 0;
    for (int j = 0; j < num_letters; ++j) {
        if (min_idx[j] == INT_MAX) {
            continue;
        }
        int counter = 0;
        for (int i = min_idx[j] + 1; i < max_idx[j]; ++i) {
            counter |= 1 << (s[i] - 'a');
        }
        count += std::bitset<32>(counter).count();
    }
    return count;
}

int CountPalindromicSubsequenceBinSearch(const std::string& s) {
    constexpr int num_letters = 'z' - 'a' + 1;
    int n = s.size();
    std::vector<int> indices[num_letters];
    for (int i = 0; i < n; ++i) {
        indices[s[i] - 'a'].push_back(i);
    }
    int count = 0;
    for (int left = 0; left < num_letters; ++left) {
        if (indices[left].size() < 2) {
            continue;
        }
        int first_idx = indices[left][0];
        int last_idx = indices[left].back();
        for (int middle = 0; middle < num_letters; ++middle) {
            auto middle_it = std::ranges::upper_bound(indices[middle],
                                                      first_idx);
            if (middle_it == indices[middle].end()) {
                continue;
            }
            count += *middle_it < last_idx;
        }
    }
    return count;
}

using std::string;

class Solution {
public:
    int countPalindromicSubsequence(const string& s) {
        return CountPalindromicSubsequenceSet(s);
    }
};
