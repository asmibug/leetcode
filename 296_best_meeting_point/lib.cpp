/**
 * We can minimize travel distance for each dimension separately
 * because of Manhattan distance.
 * For 1 dimension travel distance is minimal for a point such that
 * to the left of it and to the right of it we have same number of points,
 * i.e. median.
 * Therefore, we need to find median.
 *
 * Approaches to finding a median:
 * 0) Quickselect
 * 1) Count total number of points, after that count points
 * for each dimension independently until we get half of points.
 * 2) Store indices for each dimension.
 * 3) Count number of points for each i and j separately.
 * 
 * Approaches to distance calculation:
 * 1) First find median and after that distances from it.
 * 2) Sum forward until we find a median, after that just calculate distances.
 * 3) Two-pointers approach: move from both ends until pointers meet.
*/

#include <functional>
#include <vector>

int GetMinTotalDistByCountAndSumForward(
        const std::vector<std::vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    constexpr int kMaxSize = 200;
    unsigned char counts_i[kMaxSize] = {0};
    unsigned char counts_j[kMaxSize] = {0};
    int points_count = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            points_count += grid[i][j];
            counts_i[i] += grid[i][j];
            counts_j[j] += grid[i][j];
        }
    }

    int total_dist = 0;
    for (const auto& counts : {std::ref(counts_i), std::ref(counts_j)}) {
        int seen_points = 0;
        int idx = 0;
        while (seen_points <= points_count / 2) {
            total_dist += seen_points;
            seen_points += counts[idx];
            ++idx;
        }
        int median = idx - 1;
        while (seen_points < points_count) {
            total_dist += (idx - median) * counts[idx];
            seen_points += counts[idx];
            ++idx;
        }
    }
    return total_dist;
}

int GetMinTotalDistByCountAndTwoPointers(
        const std::vector<std::vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    constexpr int kMaxSize = 200;
    unsigned char counts_i[kMaxSize] = {0};
    unsigned char counts_j[kMaxSize] = {0};
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            counts_i[i] += grid[i][j];
            counts_j[j] += grid[i][j];
        }
    }

    int total_dist = 0;
    for (const auto& [counts, sz] : {std::pair{std::ref(counts_i), m},
                                     std::pair{std::ref(counts_j), n}}) {
        int l = -1;  // median is at l or to the right
        int r = sz;  // median is at r or to the left
        int left_count = 0;  // count up to l
        int right_count = 0;  // count starting from r
        while (l != r) {  // when l == r we found median
            if (left_count <= right_count) {
                total_dist += left_count;
                left_count += counts[++l];
            } else {
                total_dist += right_count;
                right_count += counts[--r];
            }
        }
    }
    return total_dist;
}

using std::vector;

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        return GetMinTotalDistByCountAndSumForward(grid);
    }
};
