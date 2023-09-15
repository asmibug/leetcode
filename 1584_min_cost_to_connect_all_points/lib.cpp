#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>
#include <unordered_set>

namespace {
    int GetDistance(const std::vector<int>& point1,
                    const std::vector<int>& point2) {
        return (std::abs(point1[0] - point2[0])
                + std::abs(point1[1] - point2[1]));
    }
}

int GetMinCostToConnectKruskal(const std::vector<std::vector<int>>& points) {
    int n = points.size();

    struct Edge {
        int p1_idx;
        int p2_idx;
        int distance;

        bool operator<(const Edge& other) {
            return distance < other.distance;
        }
    };

    std::vector<Edge> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            edges.push_back({i, j, GetDistance(points[i], points[j])});
        }
    }
    std::sort(edges.begin(), edges.end());

    int cost = 0;
    int edges_count = 0;
    std::vector<int> group_ids(points.size(), 0);
    int groups_num = 0;
    for (int i = 0; edges_count < n - 1; ++i) {
        auto& edge = edges[i];
        if (group_ids[edge.p1_idx] == group_ids[edge.p2_idx]
                && group_ids[edge.p1_idx] != 0) {
            continue;
        }
        cost += edge.distance;
        ++edges_count;
        if (group_ids[edge.p1_idx] == 0) {
            ++groups_num;
            group_ids[edge.p1_idx] = groups_num;
        }
        if (group_ids[edge.p2_idx] == 0) {
            group_ids[edge.p2_idx] = group_ids[edge.p1_idx];
        } else {
            auto old_group = group_ids[edge.p2_idx];
            for (int j = 0; j < n; ++j) {
                if (group_ids[j] == old_group) {
                    group_ids[j] = group_ids[edge.p1_idx];
                }
            }
        }
    }
    return cost;
}

int GetMinCostToConnectPrim(const std::vector<std::vector<int>>& points) {
    int n = points.size();
    int cost = 0;
    std::vector<int> min_distances;
    for (int i = 0; i < n; ++i) {
        min_distances.push_back(GetDistance(points[0], points[i]));
    }
    std::unordered_set<int> vertices;
    for (int i = 1; i < n; ++i) {
        vertices.insert(i);
    }
    while (!vertices.empty()) {
        int min_distance = INT_MAX;
        int vertex_id;
        for (int v_i : vertices) {
            if (min_distances[v_i] < min_distance) {
                min_distance = min_distances[v_i];
                vertex_id = v_i;
            }
        }

        cost += min_distance;

        vertices.erase(vertex_id);
        for (int v_i : vertices) {
            int distance = GetDistance(points[v_i], points[vertex_id]);
            if (distance < min_distances[v_i]) {
                min_distances[v_i] = distance;
            }
        }
    }
    return cost;
}

using std::vector;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        return GetMinCostToConnectPrim(points);
    }
};
