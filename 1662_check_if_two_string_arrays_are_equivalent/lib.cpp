/**
 * https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
 *
 * Approaches:
 * 1) Concatenate strings in vector and check strings equality
 * 2) Two-pointer approach
*/

#include <string>
#include <vector>

std::string Concatenate(const std::vector<std::string>& strings) {
    std::string res;
    for (const auto& s : strings) {
        res += s;
    }
    return res;
}

bool CheckEqualConcatenation(const std::vector<std::string>& s1,
                             const std::vector<std::string>& s2) {
    return Concatenate(s1) == Concatenate(s2);
}

bool CheckEqualTwoPointers(const std::vector<std::string>& s1,
                           const std::vector<std::string>& s2) {
    unsigned i = 0;
    unsigned j = 0;
    for (const auto& s : s2) {
        for (char c : s) {
            while (i < s1.size() && j == s1[i].size()) {
                ++i;
                j = 0;
            }
            if (i == s1.size()) {
                return false;
            }
            if (s1[i][j] != c) {
                return false;
            }
            ++j;
        }
    }
    while (i < s1.size()) {
        if (j < s1[i].size()) {
            return false;
        }
        ++i;
        j = 0;
    }
    return true;
}

using std::string;
using std::vector;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return CheckEqualTwoPointers(word1, word2);
    }
};
