#include <algorithm>
#include <string>

std::string ReverseWords(std::string& s) {
    int n = s.size();
    int begin_idx = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == ' ') {
            std::reverse(s.begin() + begin_idx, s.begin() + i);
            begin_idx = i + 1;
        }
    }
    std::reverse(s.begin() + begin_idx, s.end());
    return s;
}

std::string ReverseWords(std::string&& s) {
    return ReverseWords(s);
}

using std::string;

class Solution {
public:
    string reverseWords(string s) {
        return ReverseWords(s);
    }
};
