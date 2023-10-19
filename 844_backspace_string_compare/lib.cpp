#include <string>

std::string BackspaceToNormal(const std::string& s) {
    std::string res;
    for (char c : s) {
        if (c == '#') {
            if (!res.empty()) {
                res.pop_back();
            }
        } else {
            res.push_back(c);
        }
    }
    return res;
}

bool BackspaceCompareConstruct(const std::string& s, const std::string& t) {
    return BackspaceToNormal(s) == BackspaceToNormal(t);
}

int GetNextSymbolIdx(int current, const std::string& s) {
    int backspace_count = 0;
    --current;
    for (; current >= 0; --current) {
        if (s[current] == '#') {
            ++backspace_count;
        } else if (backspace_count) {
            --backspace_count;
        } else {
            return current;
        }
    }
    return current;
}

bool BackspaceCompareBackwards(const std::string& s, const std::string& t) {
    int i = GetNextSymbolIdx(s.size(), s);
    int j = GetNextSymbolIdx(t.size(), t);
    for (; i != -1 && j != -1;
           i = GetNextSymbolIdx(i, s), j = GetNextSymbolIdx(j, t)) {
        if (s[i] != t[j]) {
            return false;
        }
    }
    return i == j;
}

using std::string;

class Solution {
public:
    bool backspaceCompare(const string& s, const string& t) {
        return BackspaceCompareBackwards(s, t);
    }
};
