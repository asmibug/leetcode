#include <algorithm>
#include <vector>

int GetMaximumEliminationsSort(const std::vector<int>& dist,
                               const std::vector<int>& speed) {
    int n = dist.size();
    std::vector<int> steps;
    steps.reserve(n);
    for (int i = 0; i < n; ++i) {
        steps.push_back((dist[i] + speed[i] - 1) / speed[i]);
    }
    std::ranges::sort(steps);
    for (int i = 0; i < n; ++i) {
        if (i >= steps[i]) {
            return i;
        }
    }
    return n;
}

int GetMaximumEliminationsBucket(const std::vector<int>& dist,
                                 const std::vector<int>& speed) {
    int n = dist.size();
    std::vector<int> counts(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int steps = std::min(n, (dist[i] + speed[i] - 1) / speed[i]) ;
        ++counts[steps];
    }
    int total_count = counts[0];
    for (int i = 0; i < n; ++i) {
        if (total_count > i) {
            return i;
        }
        total_count += counts[i + 1];
    }
    return n;
}

using std::vector;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        return GetMaximumEliminationsBucket(dist, speed);
    }
};
