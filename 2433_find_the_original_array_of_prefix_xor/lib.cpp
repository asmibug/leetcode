#include <vector>

std::vector<int> ReverseXor(const std::vector<int>& arr) {
    std::vector<int> res;
    res.reserve(arr.size());
    int prev = 0;
    for (int x : arr) {
        res.push_back(prev ^ x);
        prev = x;
    }
    return res;
}

using std::vector;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        return ReverseXor(pref);
    }
};
