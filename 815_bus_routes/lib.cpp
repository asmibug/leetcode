#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>

std::unordered_map<int, std::vector<int>> RoutesToStops(
        const std::vector<std::vector<int>>& routes) {
    int n = routes.size();
    std::unordered_map<int, std::vector<int>> stops;
    for (int route = 0; route < n; ++route) {
        for (int stop : routes[route]) {
            stops[stop].push_back(route);
        }
    }
    return stops;
}

int GetNumBusesQueueStops(
        const std::vector<std::vector<int>>& routes, int from, int to) {
    if (from == to) {
        return 0;
    }

    auto stops = RoutesToStops(routes);

    int num_buses = 0;
    std::vector<bool> seen_routes(routes.size(), false);
    std::unordered_set seen_stops{from};
    std::queue<int> queue;
    queue.push(from);
    while (!queue.empty()) {
        for (int i = queue.size(); i > 0; --i) {
            int stop = queue.front();
            queue.pop();
            if (stop == to) {
                return num_buses;
            }
            for (int route : stops[stop]) {
                if (seen_routes[route]) {
                    continue;
                }
                seen_routes[route] = true;
                for (int next : routes[route]) {
                    if (!seen_stops.contains(next)) {
                        seen_stops.insert(next);
                        queue.push(next);
                    }
                }
            }
        }
        ++num_buses;
    }
    return -1;
}

int GetNumBusesQueueRoutes(
        const std::vector<std::vector<int>>& routes, int from, int to) {
    if (from == to) {
        return 0;
    }

    auto stops = RoutesToStops(routes);
    std::unordered_set finish_routes(stops[to].begin(), stops[to].end());

    int num_buses = 0;
    std::unordered_set seen_stops{from};
    std::vector<bool> seen_routes(routes.size(), false);
    std::queue<int> queue;
    for (int route : stops[from]) {
        seen_routes[route] = true;
        queue.push(route);
    }
    while (!queue.empty()) {
        ++num_buses;
        for (int i = queue.size(); i > 0; --i) {
            int route = queue.front();
            queue.pop();
            if (finish_routes.contains(route)) {
                return num_buses;
            }
            for (int stop : routes[route]) {
                if (seen_stops.contains(stop)) {
                    continue;
                }
                seen_stops.insert(stop);
                for (int next : stops[stop]) {
                    if (!seen_routes[next]) {
                        seen_routes[next] = true;
                        queue.push(next);
                    }
                }
            }
        }
        
    }
    return -1;
}

bool CheckIntersection(const std::vector<int>& a, const std::vector<int>& b) {
    auto it_a = a.begin();
    auto it_b = b.begin();
    while (it_a != a.end() && it_b != b.end()) {
        if (*it_a == *it_b) {
            return true;
        }
        if (*it_a < *it_b) {
            ++it_a;
        } else {
            ++it_b;
        }
    }
    return false;
}

std::vector<std::vector<bool>> GetGraphMatrix(
        std::vector<std::vector<int>>& routes) {
    for (auto& route : routes) {
        std::ranges::sort(route);
    }
    int n = routes.size();
    std::vector graph(n, std::vector<bool>(n, false));
    std::vector<int> start_routes;
    std::unordered_set<int> finish_routes;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (CheckIntersection(routes[i], routes[j])) {
                graph[i][j] = true;
                graph[j][i] = true;
            }
        }
    }
    return graph;
}

std::vector<int> GetStartRoutes(
        const std::vector<std::vector<int>>& routes, int from) {
    int n = routes.size();
    std::vector<int> start_routes;
    for (int i = 0; i < n; ++i) {
        for (int stop : routes[i]) {
            if (stop == from) {
                start_routes.push_back(i);
            }
        }
    }
    return start_routes;
}

std::unordered_set<int> GetFinishRoutes(
        const std::vector<std::vector<int>>& routes, int to) {
    int n = routes.size();
    std::unordered_set<int> finish_routes;
    for (int i = 0; i < n; ++i) {
        for (int stop : routes[i]) {
            if (stop == to) {
                finish_routes.insert(i);
            }
        }
    }
    return finish_routes;
}

int GetNumBusesRoutesMatrix(
        std::vector<std::vector<int>>& routes, int from, int to) {
    if (from == to) {
        return 0;
    }

    int n = routes.size();
    auto start_routes = GetStartRoutes(routes, from);
    auto finish_routes = GetFinishRoutes(routes, to);
    auto graph = GetGraphMatrix(routes);

    int num_buses = 0;
    std::vector<bool> seen_routes(routes.size(), false);
    std::queue<int> queue;
    for (int route : start_routes) {
        seen_routes[route] = true;
        queue.push(route);
    }
    while (!queue.empty()) {
        ++num_buses;
        for (int i = queue.size(); i > 0; --i) {
            int route = queue.front();
            queue.pop();
            if (finish_routes.contains(route)) {
                return num_buses;
            }
            for (int next = 0; next < n; ++next) {
                if (!seen_routes[next] && graph[route][next]) {
                    seen_routes[next] = true;
                    queue.push(next);
                }
            }
        }
    }
    return -1;
}

int GetNumBusesRoutesMatrix(
        std::vector<std::vector<int>>&& routes, int from, int to) {
    return GetNumBusesRoutesMatrix(routes, from, to);
}

int GetNumBusesBellmanFordMatrix(
        std::vector<std::vector<int>>& routes, int from, int to) {
    if (from == to) {
        return 0;
    }

    int n = routes.size();
    auto start_routes = GetStartRoutes(routes, from);
    auto finish_routes = GetFinishRoutes(routes, to);
    auto graph = GetGraphMatrix(routes);

    int num_buses = 0;
    std::vector<bool> routes_reached(n, false);
    auto new_routes_reached = routes_reached;
    for (int route : start_routes) {
        new_routes_reached[route] = true;
    }
    while (routes_reached != new_routes_reached) {
        routes_reached = new_routes_reached;
        ++num_buses;
        for (int i = 0; i < n; ++i) {
            if (routes_reached[i] && finish_routes.contains(i)) {
                return num_buses;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!routes_reached[i]) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (!routes_reached[j] && graph[i][j]) {
                    new_routes_reached[j] = true;
                }
            }
        }
    }
    return -1;
}

int GetNumBusesBellmanFordMatrix(
        std::vector<std::vector<int>>&& routes, int from, int to) {
    return GetNumBusesBellmanFordMatrix(routes, from, to);
}

int GetNumBusesBellmanFord(
        const std::vector<std::vector<int>>& routes, int from, int to) {
    if (from == to) {
        return 0;
    }
    constexpr int max_stop = 1e6 - 1;
    int n = routes.size();
    std::vector<short> steps_to_reach_stop(max_stop + 1, n + 1);
    steps_to_reach_stop[from] = 0;
    bool steps_changed = true;
    while (steps_changed) {
        steps_changed = false;
        for (const auto& route : routes) {
            short min_steps = n + 1;
            for (int stop : route) {
                min_steps = std::min(min_steps, steps_to_reach_stop[stop]);
            }
            ++min_steps;
            for (int stop : route) {
                if (steps_to_reach_stop[stop] > min_steps) {
                    steps_to_reach_stop[stop] = min_steps;
                    steps_changed = true;
                }
            }
        }
    }
    return steps_to_reach_stop[to] <= n ? steps_to_reach_stop[to] : -1;
}

using std::vector;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        return GetNumBusesRoutesMatrix(routes, source, target);        
    }
};
