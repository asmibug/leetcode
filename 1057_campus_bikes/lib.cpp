#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <functional>
#include <queue>
#include <tuple>
#include <unordered_set>
#include <utility>
#include <vector>

int GetDist(const std::vector<int>& a, const std::vector<int>& b) {
    return std::abs(a[0] - b[0]) + std::abs(a[1] - b[1]);
}

std::vector<int> AssignBikesSortLambda(
        const std::vector<std::vector<int>>& workers,
        const std::vector<std::vector<int>>& bikes) {
    int n = workers.size();
    int m = bikes.size();
    std::vector<std::pair<int, int>> pairs;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            pairs.push_back({i, j});
        }
    }
    std::sort(pairs.begin(), pairs.end(),
              [&workers, &bikes](const std::pair<int, int>& a,
                                 const std::pair<int, int>& b) {
                  int da = GetDist(workers[a.first], bikes[a.second]);
                  int db = GetDist(workers[b.first], bikes[b.second]);
                  return std::make_pair(da, a) < std::make_pair(db, b);
              });
    std::vector<int> assigned_workers(n, -1);
    std::vector<bool> used_bikes(m, false);
    for (auto [i, j] : pairs) {
        if (assigned_workers[i] != -1 || used_bikes[j]) {
            continue;
        }
        assigned_workers[i] = j;
        used_bikes[j] = true;
    }
    return assigned_workers;
}

struct Comparator {
    const std::vector<std::vector<int>>& workers;
    const std::vector<std::vector<int>>& bikes;

    bool operator()(std::pair<int, int> a, std::pair<int, int> b) {
        int da = GetDist(workers[a.first], bikes[a.second]);
        int db = GetDist(workers[b.first], bikes[b.second]);
        return std::make_pair(da, a) < std::make_pair(db, b);
    }
};

std::vector<int> AssignBikesSortComparator(
        const std::vector<std::vector<int>>& workers,
        const std::vector<std::vector<int>>& bikes) {
    int n = workers.size();
    int m = bikes.size();
    std::vector<std::pair<int, int>> pairs;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            pairs.push_back({i, j});
        }
    }
    std::sort(pairs.begin(), pairs.end(), Comparator{workers, bikes});
    std::vector<int> assigned_workers(n, -1);
    std::vector<bool> used_bikes(m, false);
    for (auto [i, j] : pairs) {
        if (assigned_workers[i] != -1 || used_bikes[j]) {
            continue;
        }
        assigned_workers[i] = j;
        used_bikes[j] = true;
    }
    return assigned_workers;
}

std::vector<int> AssignBikesSortPrecompute(
        const std::vector<std::vector<int>>& workers,
        const std::vector<std::vector<int>>& bikes) {
    int n = workers.size();
    int m = bikes.size();
    std::vector<std::tuple<int, int, int>> pairs;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            pairs.push_back({GetDist(workers[i], bikes[j]), i, j});
        }
    }
    std::sort(pairs.begin(), pairs.end());
    std::vector<int> assigned_workers(n, -1);
    std::vector<bool> used_bikes(m, false);
    for (auto [_, i, j] : pairs) {
        if (assigned_workers[i] != -1 || used_bikes[j]) {
            continue;
        }
        assigned_workers[i] = j;
        used_bikes[j] = true;
    }
    return assigned_workers;
}

std::vector<int> AssignBikesSortBucket(
        const std::vector<std::vector<int>>& workers,
        const std::vector<std::vector<int>>& bikes) {
    int n = workers.size();
    int m = bikes.size();
    constexpr int max_dist = 999 + 999;  // min coord is 0, max coord is 999
    std::array<std::vector<std::pair<int, int>>, max_dist + 1> dist = {};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dist[GetDist(workers[i], bikes[j])].push_back({i, j});
        }
    }
    std::vector<int> assigned_workers(n, -1);
    std::vector<bool> used_bikes(m, false);
    int assigned = 0;
    for (const auto& pairs : dist) {
        for (auto [i, j] : pairs) {
            if (assigned_workers[i] != -1 || used_bikes[j]) {
                continue;
            }
            assigned_workers[i] = j;
            used_bikes[j] = true;
            ++assigned;
            if (assigned == n) {
                return assigned_workers;
            }
        }
    }
    return assigned_workers;
}

std::vector<int> AssignBikesByWorkerHeap(
        const std::vector<std::vector<int>>& workers,
        const std::vector<std::vector<int>>& bikes) {
    int n = workers.size();
    int m = bikes.size();
    using dij = std::tuple<int, int, int>;
    auto cmp = std::greater<dij>();

    std::vector<
        std::priority_queue<dij, std::vector<dij>, decltype(cmp)>
    > distances;
    std::priority_queue<dij, std::vector<dij>, decltype(cmp)> candidates;
    {
        std::vector<dij> candidates_vect;
        candidates_vect.reserve(n);
        for (int i = 0; i < n; ++i) {
            std::vector<dij> dist;
            dist.reserve(m);
            for (int j = 0; j < m; ++j) {
                dist.push_back({GetDist(workers[i], bikes[j]), i, j});
            }
            distances.emplace_back(cmp, std::move(dist));
            candidates_vect.push_back(distances.back().top());
            distances.back().pop();
        }
        candidates = decltype(candidates)(cmp, std::move(candidates_vect));
    }

    std::vector<int> assigned_workers(n, -1);
    std::vector<bool> used_bikes(m, false);
    for (int assigned = 0; assigned < n; ++assigned) {
        auto [d, i, j] = candidates.top();
        candidates.pop();
        while (used_bikes[j]) {
            do {
                std::tie(d, i, j) = distances[i].top();
                distances[i].pop();
            } while (used_bikes[j]);
            candidates.push({d, i, j});
            std::tie(d, i, j) = candidates.top();
            candidates.pop();
        }
        assigned_workers[i] = j;
        used_bikes[j] = true;
    }
    return assigned_workers;
}

std::vector<int> AssignBikesByWorkerHeapSimpler(
        const std::vector<std::vector<int>>& workers,
        const std::vector<std::vector<int>>& bikes) {
    int n = workers.size();
    int m = bikes.size();
    using dij = std::tuple<int, int, int>;
    auto cmp = std::greater<dij>();

    std::vector<std::vector<dij>> distances(n);
    std::priority_queue<dij, std::vector<dij>, decltype(cmp)> candidates(cmp);
    for (int i = 0; i < n; ++i) {
        distances[i].reserve(m);
        for (int j = 0; j < m; ++j) {
            distances[i].push_back({GetDist(workers[i], bikes[j]), i, j});
        }
        std::ranges::sort(distances[i], cmp);
        candidates.push(distances[i].back());
        distances[i].pop_back();
    }

    std::vector<int> assigned_workers(n, -1);
    std::vector<bool> used_bikes(m, false);
    for (int assigned = 0; assigned < n; ++assigned) {
        auto [d, i, j] = candidates.top();
        candidates.pop();
        while (used_bikes[j]) {
            do {
                std::tie(d, i, j) = distances[i].back();
                distances[i].pop_back();
            } while (used_bikes[j]);
            candidates.push({d, i, j});
            std::tie(d, i, j) = candidates.top();
            candidates.pop();
        }
        assigned_workers[i] = j;
        used_bikes[j] = true;
    }
    return assigned_workers;
}

std::vector<int> AssignBikesByWorkerGaleShapley(
        const std::vector<std::vector<int>>& workers,
        const std::vector<std::vector<int>>& bikes) {
    int n = workers.size();
    int m = bikes.size();
    using pair = std::pair<int, int>;
    auto cmp = std::greater<pair>();

    std::vector<
        std::priority_queue<pair, std::vector<pair>, decltype(cmp)>
    > workers_choices;
    workers_choices.reserve(n);
    for (int i = 0; i < n; ++i) {
        std::vector<pair> worker_choices;
        worker_choices.reserve(m);
        for (int j = 0; j < m; ++j) {
            auto dist = GetDist(workers[i], bikes[j]);
            worker_choices.push_back({dist, j});
        }
        workers_choices.emplace_back(cmp, std::move(worker_choices));
    }

    std::vector<pair> assigned_bikes(m, {INT_MAX, -1});
    for (int matched = 0; matched < n; ++matched) {
        int i = matched;
        do {
            auto [d, j] = workers_choices[i].top();
            workers_choices[i].pop();
            int new_i = i;
            if (pair{d, i} < assigned_bikes[j]) {
                new_i = assigned_bikes[j].second;
                assigned_bikes[j] = {d, i};
            }
            i = new_i;
        } while (i >= 0);
    }
    std::vector<int> assigned_workers(n);
    for (int j = 0; j < m; ++j) {
        if (assigned_bikes[j].second >= 0) {
            assigned_workers[assigned_bikes[j].second] = j;
        }
    }
    return assigned_workers;
}

std::vector<int> AssignBikesByWorkerGraph(
        const std::vector<std::vector<int>>& workers,
        const std::vector<std::vector<int>>& bikes) {
    int n = workers.size();
    int m = bikes.size();
    using pair = std::pair<int, int>;
    auto cmp = std::greater<pair>();

    std::vector<
        std::priority_queue<pair, std::vector<pair>, decltype(cmp)>
    > workers_choices;
    auto bikes_choices = workers_choices;
    workers_choices.reserve(n);
    bikes_choices.reserve(m);
    {
        std::vector<std::vector<pair>> bike_choices(m);
        for (int j = 0; j < m; ++j) {
            bike_choices[j].reserve(n);
        }
        for (int i = 0; i < n; ++i) {
            std::vector<pair> worker_choices;
            worker_choices.reserve(m);
            for (int j = 0; j < m; ++j) {
                auto dist = GetDist(workers[i], bikes[j]);
                worker_choices.push_back({dist, j});
                bike_choices[j].push_back({dist, i});
            }
            workers_choices.emplace_back(cmp, std::move(worker_choices));
        }
        for (int j = 0; j < m; ++j) {
            bikes_choices.emplace_back(cmp, std::move(bike_choices[j]));
        }
    }

    std::vector<int> assigned_workers(n, -1);
    std::vector<bool> used_bikes(m, false);
    for (int matched = 0; matched < n; ++matched) {
        int i = 0;
        while (assigned_workers[i] >= 0) {
            ++i;
        }
        while (true) {
            auto [d, j] = workers_choices[i].top();
            while (used_bikes[j]) {
                workers_choices[i].pop();
                std::tie(d, j) = workers_choices[i].top();
            }
            auto [d_new, i_new] = bikes_choices[j].top();
            if (i_new == i) {
                assigned_workers[i] = j;
                used_bikes[j] = true;
                break;
            }
            i = i_new;
            while (assigned_workers[i] >= 0) {
                bikes_choices[j].pop();
                std::tie(d, i) = bikes_choices[j].top();
            }
        }
    }
    return assigned_workers;
}

int GetClosestIdx(const std::vector<std::vector<int>>& from_points,
                  int from_index,
                  const std::vector<std::vector<int>>& to_points,
                  const std::unordered_set<int>& to_indices,
                  std::vector<int>* cache) {
    if (to_indices.contains((*cache)[from_index])) {
        return (*cache)[from_index];
    }
    int min_dist = INT_MAX;
    int min_idx = -1;
    for (int idx : to_indices) {
        auto dist = GetDist(from_points[from_index], to_points[idx]);
        if (std::pair{dist, idx} < std::pair{min_dist, min_idx}) {
            min_dist = dist;
            min_idx = idx;
        }
    }
    (*cache)[from_index] = min_idx;
    return min_idx;
}

std::vector<int> AssignBikesByWorkerGraphSimple(
        const std::vector<std::vector<int>>& workers,
        const std::vector<std::vector<int>>& bikes) {
    int n = workers.size();
    int m = bikes.size();

    std::unordered_set<int> free_workers;
    for (int i = 0; i < n; ++i) {
        free_workers.insert(i);
    }
    auto free_bikes = free_workers;
    for (int j = n; j < m; ++j) {
        free_bikes.insert(j);
    }

    std::vector<int> assigned_workers(n, -1);
    std::vector<int> assigned_bikes(m, -1);
    while (!free_workers.empty()) {
        int i = *free_workers.begin();
        int j = GetClosestIdx(workers, i, bikes, free_bikes, &assigned_workers);
        while (true) {
            int i_next = GetClosestIdx(
                bikes, j, workers, free_workers, &assigned_bikes);
            if (i_next == i) {
                break;
            }
            i = i_next;
            int j_next = GetClosestIdx(
                workers, i, bikes, free_bikes, &assigned_workers);
            if (j_next == j) {
                break;
            }
            j = j_next;
        }
        free_workers.erase(i);
        free_bikes.erase(j);
    }
    return assigned_workers;
}

struct Point {
    int x;
    int y;
    int idx;

    bool operator==(const Point& p) const {
        return idx == p.idx;
    }
};

template<>
struct std::hash<Point> {
    std::size_t operator()(const Point& p) const {
        return (static_cast<std::size_t>(p.x) << 32) + p.y;
    }
};

int GetDist(const Point& a, const Point& b) {
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

Point GetClosest(const Point& from,
                 const std::unordered_set<Point>& to,
                 std::vector<Point>* cache) {
    if (to.contains((*cache)[from.idx])) {
        return (*cache)[from.idx];
    }
    int min_dist = INT_MAX;
    Point min_point;
    for (const auto& p : to) {
        auto dist = GetDist(from, p);
        if (std::pair{dist, p.idx} < std::pair{min_dist, min_point.idx}) {
            min_dist = dist;
            min_point = p;
        }
    }
    (*cache)[from.idx] = min_point;
    return min_point;
}

std::vector<int> AssignBikesByWorkerGraphOptimized(
        const std::vector<std::vector<int>>& workers,
        const std::vector<std::vector<int>>& bikes) {
    int n = workers.size();
    int m = bikes.size();

    std::unordered_set<Point> free_workers;
    for (int i = 0; i < n; ++i) {
        free_workers.insert({workers[i][0], workers[i][1], i});
    }
    std::unordered_set<Point> free_bikes;
    for (int j = 0; j < m; ++j) {
        free_bikes.insert({bikes[j][0], bikes[j][1], j});
    }

    std::vector<int> assigned_workers(n, -1);
    std::vector<Point> workers_cache(n, {0, 0, -1});
    std::vector<Point> bikes_cache(m, {0, 0, -1});
    std::vector<Point> stack;
    while (!free_workers.empty()) {
        auto i = *free_workers.begin();
        if (!stack.empty()) {
            i = stack.back();
            stack.pop_back();
        }
        auto j = GetClosest(i, free_bikes, &workers_cache);
        auto i_next = GetClosest(j, free_workers, &bikes_cache);
        if (i_next != i) {
            stack.clear();
            stack.push_back(i);
            i = i_next;
        }
        while (true) {
            auto j_next = GetClosest(i, free_bikes, &workers_cache);
            if (j_next == j) {
                break;
            }
            j = j_next;

            i_next = GetClosest(j, free_workers, &bikes_cache);
            if (i_next == i) {
                break;
            }
            stack.push_back(i);
            i = i_next;
        }
        free_workers.erase(i);
        free_bikes.erase(j);
        assigned_workers[i.idx] = j.idx;
    }
    return assigned_workers;
}

using std::vector;

class Solution {
public:
    vector<int> assignBikes(const vector<vector<int>>& workers,
                            const vector<vector<int>>& bikes) {
        return AssignBikesSortPrecompute(workers, bikes);
    }
};
