#include <algorithm>
#include <vector>

int GetLastMoment(int n, const std::vector<int>& left, const std::vector<int>& right) {
    int res = 0;
    if (!left.empty()) {
        res = std::max(res, *std::ranges::max_element(left));
    }
    if (!right.empty()) {
        res = std::max(res, n - *std::ranges::min_element(right));
    }
    return res;
}

using std::vector;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        return GetLastMoment(n, left, right);
    }
};
