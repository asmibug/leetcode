#include <algorithm>
#include <vector>

std::vector<int> GetWeakestRowsIndices(const std::vector<std::vector<int>>& mat,
                                       int k) {
    std::vector<int> powers;
    for (auto& row : mat) {
        powers.push_back(
            row.rend() - std::upper_bound(row.rbegin(), row.rend(), 0));
    }

    std::vector<int> indices;
    for (int i = 0; i - mat.size(); ++i) {
        indices.push_back(i);
    }
    std::stable_sort(indices.begin(), indices.end(), [&powers](int i, int j) {
        return powers[i] < powers[j];
    });
    indices.resize(k);
    return indices;
}

using std::vector;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        return GetWeakestRowsIndices(mat, k);
    }
};
