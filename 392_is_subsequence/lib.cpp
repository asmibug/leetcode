#include <string>

bool IsSubsequence(const std::string& s, const std::string& t) {
    unsigned symbols_matched = 0;
    for (unsigned i = 0; i < t.size() && symbols_matched < s.size(); ++i) {
        if (s[symbols_matched] == t[i]) {
            ++symbols_matched;
        }
    }
    return symbols_matched == s.size();
}

using std::string;

class Solution {
public:
    bool isSubsequence(const string& s, const string& t) {
        return IsSubsequence(s, t);
    }
};
