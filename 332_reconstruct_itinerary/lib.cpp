#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace {
    void DFS(
        const std::vector<std::vector<std::string>>& tickets,
        const std::unordered_map<std::string, std::vector<int>>& graph,
        const std::string& from,
        std::unordered_set<int>& used,
        std::vector<std::string>& route
    ) {
        if (used.size() == tickets.size()) {
            return;
        }
        if (!graph.contains(from)) {
            return;
        }
        for (int edge_idx : graph.at(from)) {
            if (used.contains(edge_idx)) {
                continue;
            }
            used.insert(edge_idx);
            auto next = tickets[edge_idx][1];
            route.push_back(next);
            DFS(tickets, graph, next, used, route);
            if (used.size() == tickets.size()) {
                return;
            }
            route.pop_back();
            used.erase(edge_idx);
        }
    }
}

std::vector<std::string> FindItinerarySlow(
        std::vector<std::vector<std::string>>& tickets) {
    int n = tickets.size();
    std::sort(tickets.begin(), tickets.end(), [](
        const std::vector<std::string>& a,
        const std::vector<std::string>& b
    ) {
        return a[1] < b[1];
    });

    std::unordered_map<std::string, std::vector<int>> graph;
    for (int i = 0; i < n; ++i) {
        graph[tickets[i][0]].push_back(i);
    }
    std::unordered_set<int> tickets_used;
    std::vector<std::string> route = {"JFK"};
    DFS(tickets, graph, "JFK", tickets_used, route);
    return route;
}


namespace {
    void BuildRoute(
        const std::string& from,
        std::unordered_map<std::string, std::vector<std::string>>& graph,
        std::vector<std::string>& route
    ) {
        auto& next_vertices = graph[from];
        while (!next_vertices.empty()) {
            auto next = next_vertices.back();
            next_vertices.pop_back();
            BuildRoute(next, graph, route);
        }
        route.push_back(from);
    }
}

std::vector<std::string> FindItinerary(
        std::vector<std::vector<std::string>>& tickets) {
    std::unordered_map<std::string, std::vector<std::string>> graph;
    for (auto& ticket : tickets) {
        graph[ticket[0]].push_back(ticket[1]);
    }
    for (auto& [key, value] : graph) {
        std::sort(value.rbegin(), value.rend());
    }
    std::vector<std::string> route;
    BuildRoute("JFK", graph, route);
    std::reverse(route.begin(), route.end());
    return route;
}

using std::string;
using std::vector;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        return FindItinerary(tickets);
    }
};
