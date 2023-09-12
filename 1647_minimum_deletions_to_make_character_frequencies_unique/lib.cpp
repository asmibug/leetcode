#include <algorithm>  // std::sort
#include <functional>  // std::greater
#include <string>  // std::string

int GetMinDeletions(const std::string& s) {
    constexpr int symbols_num = 'z' - 'a' + 1;
    int counts[symbols_num] = {0};
    for (char c : s) {
        ++counts[c - 'a'];
    }
    std::sort(&counts[0], &counts[symbols_num], std::greater<int>());

    int deletions_count = 0;
    int max_allowed = s.size();
    for (int count : counts) {
        if (count > max_allowed) {
            deletions_count += count - max_allowed;
            count = max_allowed;
        }
        max_allowed = count > 0 ? count - 1 : 0;
    }
    return deletions_count;
}

using std::string;

class Solution {
public:
    int minDeletions(string s) {
        return GetMinDeletions(s);
    }
};
