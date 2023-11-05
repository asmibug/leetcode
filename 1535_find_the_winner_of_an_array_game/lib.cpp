#include <vector>

int GetWinner(const std::vector<int>& arr, int k) {
    int n = arr.size();
    int max = arr[0];
    int count = 0;
    for (int i = 1; i < n && count < k; ++i) {
        if (arr[i] > max) {
            max = arr[i];
            count = 0;
        }
        ++count;
    }
    return max;
}

using std::vector;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        return GetWinner(arr, k);
    }
};
