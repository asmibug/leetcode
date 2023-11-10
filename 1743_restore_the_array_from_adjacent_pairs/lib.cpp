#include <unordered_map>
#include <unordered_set>
#include <vector>


std::vector<int> RestoreArrayHash(const std::vector<std::vector<int>>& pairs) {
    std::unordered_map<int, std::vector<int>> neighbors;
    for (const auto& p : pairs) {
        for (int i = 0; i < 2; ++i) {
            neighbors[p[i]].push_back(p[!i]);
        }
    }
    int prev = neighbors.begin()->first;
    for (const auto& [from, to] : neighbors) {
        if (to.size() == 1) {
            prev = from;
            break;
        }
    }
    int cur = neighbors[prev][0];
    std::vector result = {prev, cur};
    while (result.size() < neighbors.size()) {
        const auto& candidates = neighbors[cur];
        int next = candidates[0] != prev ? candidates[0] : candidates[1];
        prev = cur;
        cur = next;
        result.push_back(cur);
    }
    return result;
}

using std::vector;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        return RestoreArrayHash(adjacentPairs);
    }
};
