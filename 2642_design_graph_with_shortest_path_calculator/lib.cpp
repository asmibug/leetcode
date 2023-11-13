#include <algorithm>
#include <climits>
#include <functional>
#include <queue>
#include <vector>

using std::vector;

class GraphDijkstra {
public:
    GraphDijkstra(int n, const vector<vector<int>>& edges)
        : graph_(n) {
        for (const auto& edge : edges) {
            addEdge(edge);
        }
    }
    
    void addEdge(const vector<int>& edge) {
        graph_[edge[0]].push_back({edge[2], edge[1]});
    }
    
    int shortestPath(int node1, int node2) {
        std::vector<int> distances(graph_.size(), INT_MAX);
        distances[node1] = 0;
        std::priority_queue min_paths{std::greater<std::pair<int, int>>(),
                                      std::vector{std::pair{0, node1}}};
        while (!min_paths.empty()) {
            auto [dist, node] = min_paths.top();
            min_paths.pop();
            if (dist > distances[node]) {
                continue;
            }
            if (node == node2) {
                return dist;
            }
            for (auto [weight, next] : graph_[node]) {
                int next_dist = dist + weight;
                if (next_dist < distances[next]) {
                    distances[next] = next_dist;
                    min_paths.push({next_dist, next});
                }
            }
        }
        return -1;
    }

private:
    vector<vector<std::pair<int, int>>> graph_;
};

class GraphFloydWarshall {
public:
    GraphFloydWarshall(int n, const vector<vector<int>>& edges)
            : distances_(n, std::vector(n, kMaxDist)) {
        for (int i = 0; i < n; ++i) {
            distances_[i][i] = 0;
        }
        if (edges.size() < static_cast<unsigned>(n)) {
            for (const auto& edge : edges) {
                addEdge(edge);
            }
            return;
        }
        for (const auto& edge : edges) {
            distances_[edge[0]][edge[1]] = edge[2];
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    distances_[i][j] = std::min(
                        distances_[i][j], distances_[i][k] + distances_[k][j]);
                }
            }
        }
    }

    void addEdge(const vector<int>& edge) {
        int n = distances_.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                distances_[i][j] = std::min(
                    distances_[i][j],
                    distances_[i][edge[0]] + edge[2] + distances_[edge[1]][j]);
            }
        }
    }

    int shortestPath(int node1, int node2) {
        return (distances_[node1][node2] < kMaxDist
                ? distances_[node1][node2]
                : -1);
    }

private:
    std::vector<std::vector<int>> distances_;
    static constexpr int kMaxDist = 1e9;
};

class GraphFloydWarshallOptimized {
public:
    GraphFloydWarshallOptimized(int n, const vector<vector<int>>& edges)
            : n_(n) {
        std::fill(distances_.begin(), distances_.begin() + n * n, kMaxDist);
        for (int i = 0; i < n; ++i) {
            distances_[i * n + i] = 0;
        }
        if (edges.size() < static_cast<unsigned>(n)) {
            for (const auto& edge : edges) {
                addEdge(edge);
            }
            return;
        }
        for (const auto& edge : edges) {
            distances_[edge[0] * n + edge[1]] = edge[2];
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    distances_[i * n + j] = std::min(
                        distances_[i * n + j],
                        distances_[i * n + k] + distances_[k * n + j]);
                }
            }
        }
    }

    void addEdge(const vector<int>& edge) {
        for (int i = 0; i < n_; ++i) {
            for (int j = 0; j < n_; ++j) {
                distances_[i * n_ + j] = std::min(
                    distances_[i * n_ + j],
                    distances_[i * n_ + edge[0]] + edge[2]
                    + distances_[edge[1] * n_ + j]);
            }
        }
    }

    int shortestPath(int node1, int node2) {
        return (distances_[node1 * n_ + node2] < kMaxDist
                ? distances_[node1 * n_ + node2]
                : -1);
    }

private:
    std::array<int, 10000> distances_;
    int n_;
    static constexpr int kMaxDist = 1e9;
};

using Graph = GraphFloydWarshallOptimized;

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
 