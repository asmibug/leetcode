#include <string>

constexpr int kMod = 1e9 + 7;

int CountHomogenous(const std::string& s) {
    int total_count = 0;
    char prev = '\0';
    int count = 0;
    for (char c : s) {
        if (c != prev) {
            total_count = (total_count + (1LL + count) * count / 2) % kMod;
            prev = c;
            count = 0;
        }
        ++count;
    }
    total_count = (total_count + (1LL + count) * count / 2) % kMod;
    return total_count;
}

using std::string;

class Solution {
public:
    int countHomogenous(const string& s) {
        return CountHomogenous(s);
    }
};
