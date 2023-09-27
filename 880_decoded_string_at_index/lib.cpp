#include <cctype>
#include <cstdint>
#include <string>

std::string DecodeAtIndex(const std::string& s, int k) {
    int n = s.size();
    uint64_t index = k - 1;

    uint64_t len = 0;
    int i = 0;
    for (; i < n && index >= len; ++i) {
        if (!isdigit(s[i])) {
            ++len;
        } else {
            len *= s[i] - '0';
        }
    }
    for (; i > 0; --i) {
        if (!isdigit(s[i - 1])) {
            if (index == len - 1) {
                return s.substr(i - 1, 1);
            }
            --len;
        } else {
            len /= s[i - 1] - '0';
            index %= len;
        }
    }
    return "";
}

using std::string;

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        return DecodeAtIndex(s, k);
    }
};
