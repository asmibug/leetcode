#include <string>
#include <vector>

std::string RemoveDuplicateLetters(const std::string& s) {
    int n = s.size();
    constexpr int letters_num = 'z' - 'a' + 1;
    int max_idx[letters_num];
    for (int i = 0; i < n; ++i) {
        max_idx[s[i] - 'a'] = i;
    }
    std::string result;
    std::vector<bool> in_result(letters_num, false);
    for (int i = 0; i < n; ++i) {
        if (in_result[s[i] - 'a']) {
            continue;
        }
        while (!result.empty() && result.back() > s[i]
                && max_idx[result.back() - 'a'] > i) {
            in_result[result.back() - 'a'] = false;
            result.pop_back();
        }
        result.push_back(s[i]);
        in_result[s[i] - 'a'] = true;
    }
    return result;
}

using std::string;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        return RemoveDuplicateLetters(s);
    }
};
