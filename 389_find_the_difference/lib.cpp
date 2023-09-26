#include <string>

char FindTheDifference(const std::string& s, const std::string& t) {
    char difference = '\0';
    for (auto c : s) {
        difference ^= c;
    }
    for (auto c : t) {
        difference ^= c;
    }
    return difference;
}

using std::string;

class Solution {
public:
    char findTheDifference(const string& s, const string& t) {
        return FindTheDifference(s, t);
    }
};
