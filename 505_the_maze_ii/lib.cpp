#include <climits>
#include <compare>
#include <functional>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct Point {
    int x;
    int y;

    friend bool operator==(const Point& a, const Point& b) {
        return a.x == b.x && a.y == b.y;
    }
};

template<>
struct std::hash<Point> {
    std::size_t operator()(const Point& p) const {
        return (static_cast<std::size_t>(p.x) << CHAR_BIT * sizeof(p.y)) + p.y;
    }
};

struct Path {
    Point to;
    int distance;

    friend std::strong_ordering operator<=>(const Path& a, const Path& b) {
        return a.distance <=> b.distance;
    }
};


std::vector<Path> GetNeighbors(const Point& p,
                               const std::vector<std::vector<int>>& maze) {
    static const std::vector<Point> directions = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int nx = maze.size();
    int ny = maze[0].size();
    std::vector<Path> neighbors;
    for (const auto& direction : directions) {
        Point n = {p.x + direction.x, p.y + direction.y};
        int distance = 0;
        while (0 <= n.x && n.x < nx
               && 0 <= n.y && n.y < ny
               && maze[n.x][n.y] == 0) {
            ++distance;
            n = {n.x + direction.x, n.y + direction.y};
        }
        n = {n.x - direction.x, n.y - direction.y};
        if (distance) {
            neighbors.push_back({n, distance});
        }
    }
    return neighbors;
}

int GetShortestDistance(const std::vector<std::vector<int>>& maze,
                        const Point& start,
                        const Point& destination) {
    std::unordered_map<Point, int> distances = {{start, 0}};
    std::unordered_set<Point> visited;
    std::priority_queue<Path, std::vector<Path>, std::greater<Path>> min_paths;
    min_paths.push({start, 0});
    while (!min_paths.empty()) {
        auto p = std::move(min_paths.top());
        min_paths.pop();
        if (visited.contains(p.to)) {
            continue;
        }
        visited.insert(p.to);
        if (p.to == destination) {
            return distances[destination];
        }
        for (auto&& n : GetNeighbors(p.to, maze)) {
            if (visited.contains(n.to)) {
                continue;
            }
            int distance = distances[p.to] + n.distance;
            if (!distances.contains(n.to) || distances[n.to] > distance) {
                distances[n.to] = distance;
                min_paths.push({n.to, distance});
            }
        }
    }
    return -1;
}

using std::vector;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        return GetShortestDistance(maze,
                                   {start[0], start[1]},
                                   {destination[0], destination[1]});
    }
};
