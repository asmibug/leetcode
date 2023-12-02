/**
 * https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
 * We need to check that one set of letters is the subset of another set
 * 
 * Approaches:
 * 1) Brute-force: each time look for symbols in chars and remove them
 * 2) Sort: Check that sorted word is subsequence of sorted chars
 * 3) Map: Check that frequencies of letters in words are not more than in chars
*/

#include <algorithm>
#include <string>
#include <vector>

int GetSumOfValidWordsBySort(const std::vector<std::string>& words,
                             const std::string& chars) {
    std::string etalon = chars;
    std::ranges::sort(etalon);

    int res = 0;
    for (std::string word: words) {
        std::ranges::sort(word);

        bool is_valid = true;
        unsigned etalon_idx = 0;
        for (char c : word) {
            while (etalon_idx < etalon.size() && etalon[etalon_idx] < c) {
                ++etalon_idx;
            }
            if (etalon_idx == etalon.size() || etalon[etalon_idx] > c) {
                is_valid = false;
                break;
            }
            // here we have etalon[etalon_dix] == c
            ++etalon_idx;  // use each symbol only one time
        }
        if (is_valid) {
            res += word.size();
        }
    }
    return res;
}

int GetSumOfValidWordsByCount(const std::vector<std::string>& words,
                              const std::string& chars) {
    constexpr int kSymbolsNum = 'z' - 'a' + 1;

    unsigned char etalon_counts[kSymbolsNum] = {0};
    for (char c : chars) {
        ++etalon_counts[c - 'a'];
    }

    int res = 0;
    for (const auto& word : words) {
        unsigned char counts[kSymbolsNum] = {0};
        for (char c : word) {
            ++counts[c - 'a'];
        }

        bool is_valid = true;
        for (int i = 0; i < kSymbolsNum && is_valid; ++i) {
            is_valid &= counts[i] <= etalon_counts[i];
        }
        res += is_valid * word.size();
    }
    return res;
}

using std::string;
using std::vector;

class Solution {
public:
    int countCharacters(vector<string>& words, const string& chars) {
        return GetSumOfValidWordsByCount(words, chars);
    }
};
