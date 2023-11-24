#include <algorithm>
#include <vector>

/**
 * max_{i != j, k, l}(|a[i][k] - a[j][l]|)
 * = max_{i != j}(a[i][-1] - a[j][0], a[j][-1] - a[i][0])
 * = max_{i < j}(a[i][-1] - a[j][0], a[j][-1] - a[i][0])
 * = max_j(max_{i < j}(a[i][-1]) - a[j][0], a[j][-1] - min_{i < j}(a[i][0]))
*/
int GetMaxDistance(const std::vector<std::vector<int>>& arrays) {
    int min = arrays[0][0];
    int max = arrays[0].back();
    int max_distance = 0;
    for (unsigned j = 1; j < arrays.size(); ++j) {
        max_distance = std::max({
            max_distance, max - arrays[j][0], arrays[j].back() - min});
        min = std::min(min, arrays[j][0]);
        max = std::max(max, arrays[j].back());
    }
    return max_distance;
}

using std::vector;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        return GetMaxDistance(arrays);
    }
};
