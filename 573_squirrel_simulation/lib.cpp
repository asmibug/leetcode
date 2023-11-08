#include <cmath>
#include <vector>

int GetDist(const std::vector<int>& a, const std::vector<int>& b) {
    return std::abs(a[0] - b[0]) + std::abs(a[1] - b[1]);
}

int GetTotalDistance(int h, int w,
                     const std::vector<int>& tree,
                     const std::vector<int>& squirrel,
                     const std::vector<std::vector<int>>& nuts) {
    int dist = 0;
    int diff = h + w;
    for (const auto& nut : nuts) {
        dist += 2 * GetDist(tree, nut);
        int d = GetDist(squirrel, nut) - GetDist(tree, nut);
        if (d < diff) {
            diff = d;
        }
    }
    return dist + diff;
}

using std::vector;

class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        return GetTotalDistance(height, width, tree, squirrel, nuts);
    }
};
