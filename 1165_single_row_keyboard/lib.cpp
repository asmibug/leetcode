#include <cmath>
#include <string>

int CalculateTime(const std::string& keyboard, const std::string& word) {
    constexpr int kNumKeys = 'z' - 'a' + 1;
    unsigned char key2pos[kNumKeys];
    int pos = 0;
    for (unsigned char key : keyboard) {
        key2pos[key - 'a'] = pos++;
    }
    int res = 0;
    pos = 0;
    for (unsigned char key : word) {
        int new_pos = key2pos[key - 'a'];
        res += std::abs(new_pos - pos);
        pos = new_pos;
    }
    return res;
}

using std::string;

class Solution {
public:
    int calculateTime(const string& keyboard, const string& word) {
        return CalculateTime(keyboard, word);
    }
};
