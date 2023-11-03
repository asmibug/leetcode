#include <string>
#include <vector>

std::vector<std::string> BuildArray(const std::vector<int>& target, int n) {
    int m = target.size();
    std::vector<std::string> res;
    int target_pos = 0;
    for (int i = 1; i <= n && target_pos < m; ++i) {
        res.push_back("Push");
        if (i == target[target_pos]) {
            ++target_pos;
        } else {
            res.push_back("Pop");
        }
    }
    return res;
}

using std::string;
using std::vector;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        return BuildArray(target, n);
    }
};
