#include <cctype>
#include <string>

bool IsVowel(char c) {
    switch (std::tolower(c)) {
    case 'a': case 'e': case 'i': case 'o': case 'u':
        return true;
    default:
        return false;
    }
}

std::string SortVowels(const std::string& s) {
    constexpr int max_val = std::max('z', 'Z');
    int counts[max_val + 1] = {0};
    for (int c : s) {
        counts[c] += IsVowel(c);
    }
    std::string res;
    res.reserve(s.size());
    int counted_symbol = 0;
    for (char c : s) {
        if (!IsVowel(c)) {
            res.push_back(c);
            continue;
        }
        while (counts[counted_symbol] == 0) {
            ++counted_symbol;
        }
        res.push_back(counted_symbol);
        --counts[counted_symbol];
    }
    return res;
}

using std::string;

class Solution {
public:
    string sortVowels(const string& s) {
        return SortVowels(s);
    }
};
