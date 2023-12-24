/**
 * Main approach: sliding window
 * 
 * Approaches:
 * 1) Shrinkable window, store last symbol change (specific for this task)
 * 1.1) Store same char streak
 * 1.2) Store indices
 * 2) Shrinkable window, store last index for each symbol
 * 3) Shrinkable window, store symbol frequencies
 * 4) Monotonous window, store symbol frequencies
 * 
 * To store something for each symbol we can use either hasmap or array
*/

#include <algorithm>
#include <string>
#include <unordered_map>


int GetLenOfLongestSubstrShrinkableLastChange(const std::string& s) {
    int n = s.size();

    int max_len = 0;
    int left = 0;
    char prev_symbol = '\0';
    char cur_symbol = '\0';
    int last_change_idx = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != cur_symbol) {
            if (s[i] != prev_symbol) {
                max_len = std::max(max_len, i - left);
                left = last_change_idx;
            }
            prev_symbol = cur_symbol;
            cur_symbol = s[i];
            last_change_idx = i;
        }
    }
    max_len = std::max(max_len, n - left);
    return max_len;
}

int GetLenOfLongestSubstrShrinkableCountStreak(const std::string& s) {
    int max_len = 0;
    char prev_symbol = '\0';
    char cur_symbol = '\0';
    int same_char_streak = 0;
    int prev_len = 0;
    for (char c : s) {
        if (c != cur_symbol) {
            prev_len = prev_len * (c == prev_symbol) + same_char_streak;
            prev_symbol = cur_symbol;
            cur_symbol = c;
            same_char_streak = 0;
        }
        ++same_char_streak;
        max_len = std::max(max_len, prev_len + same_char_streak);
    }
    return max_len;
}

int GetLenOfLongestSubstrShrinkableIndices(const std::string& s) {
    int n = s.size();
    int max_len = 0;
    int left = 0;
    int prev_right = -1;
    for (int right = 1; right < n; ++right) {
        if (s[right] != s[right - 1]) {
            if (prev_right >= 0 && s[right] != s[prev_right]) {
                max_len = std::max(max_len, right - left);
                left = prev_right + 1;
            }
            prev_right = right - 1;
        }
    }
    return std::max(max_len, n - left);
}

int GetLenOfLongestSubstrShrinkableLastIndex(const std::string& s) {
    int n = s.size();
    
    int max_len = 0;
    std::unordered_map<char, int> last_indices;
    int left = 0;
    for (int i = 0; i < n; ++i) {
        last_indices[s[i]] = i;
        if (last_indices.size() > 2) {
            int min_idx = s.size();
            for (auto [c, idx] : last_indices) {
                min_idx = std::min(min_idx, idx);
            }
            left = min_idx + 1;
            last_indices.erase(s[min_idx]);
        }
        max_len = std::max(max_len, i - left + 1);        
    }
    return max_len;
}

constexpr int kMaxLetter = std::max('z', 'Z');
static int counts[kMaxLetter + 1];

int GetLenOfLongestSubstrShrinkableCounts(const std::string& s) {
    int n = s.size();

    int max_len = 0;
    int distinct_count = 0;
    int left = 0;
    for (int i = 0; i < n; ++i) {
        int c = s[i];
        distinct_count += counts[c] == 0;
        ++counts[c];
        while (distinct_count > 2) {
            int left_c = s[left];
            --counts[left_c];
            distinct_count -= counts[left_c] == 0;
            ++left;
        }
        max_len = std::max(max_len, i - left + 1);
    }
    std::fill(std::begin(counts), std::end(counts), 0);
    return max_len;
}

int GetLenOfLongestSubstrMonotonous(const std::string& s) {
    int distinct_count = 0;
    int left = 0;
    for (int c : s) {
        distinct_count += counts[c] == 0;
        ++counts[c];
        if (distinct_count > 2) {
            int left_c = s[left];
            --counts[left_c];
            distinct_count -= counts[left_c] == 0;
            ++left;
        }
    }
    std::fill(std::begin(counts), std::end(counts), 0);
    return s.size() - left;
}

using std::string;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(const string& s) {
        return GetLenOfLongestSubstrShrinkableIndices(s);
    }
};
