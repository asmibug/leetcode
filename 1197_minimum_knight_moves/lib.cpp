#include <climits>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <utility>
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
        return (static_cast<std::size_t>(p.x) << 32) + p.y;
    }
};

int GetDist(const Point& a, const Point& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int GetMinSteps(const Point& a, const Point& b) {
    return std::ceil(std::sqrt(GetDist(a, b) / 5.f));
}

struct Info {
    int dist;
    int steps;
};

int GetMinKnightMovesHeap(int x, int y) {
    Point goal = {x, y};
    Point start = {0, 0};
    if (start == goal) {
        return 0;
    }

    int min_steps = INT_MAX;
    std::unordered_map<Point, Info> info;
    info[start] = {GetDist(start, goal), 0};
    auto cmp = [&info](const Point& a, const Point& b) {
        return info.at(a).dist > info.at(b).dist;
    };
    std::priority_queue<Point, std::vector<Point>, decltype(cmp)> queue(cmp);
    queue.push(start);
    while (!queue.empty()) {
        Point p = queue.top();
        queue.pop();
        Info i = info.at(p);
        if (i.steps + GetMinSteps(p, goal) >= min_steps) {
            continue;
        }
        for (auto step : {Point{2, 1}, Point{1, 2},
                          Point{-1, 2}, Point{-2, 1},
                          Point{-2, -1}, Point{-1, -2},
                          Point{1, -2}, Point{2, -1}}) {
            Point next = {p.x + step.x, p.y + step.y};
            if (next == goal) {
                min_steps = i.steps + 1;
                continue;
            }
            if (info.contains(next) && i.steps + 1 >= info[next].steps) {
                continue;
            }
            info[next] = {GetDist(next, goal), i.steps + 1};
            queue.push(next);
        }
    }
    return min_steps;
}

class Solution {
public:
    int minKnightMoves(int x, int y) {
        return GetMinKnightMovesHeap(x, y);
    }
};
