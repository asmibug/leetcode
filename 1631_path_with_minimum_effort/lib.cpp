#include <climits>
#include <cstdlib>
#include <vector>

struct Point {
    int x;
    int y;
    const std::vector<std::vector<int>>& heights;

    Point(int x, int y, const std::vector<std::vector<int>>& heights)
        : x(x), y(y), heights(heights) {
    }

    Point(int idx, const std::vector<std::vector<int>>& heights)
        : x(idx / heights.size()), y(idx % heights.size()), heights(heights) {
    }
    
    int GetIdx() const {
        return heights.size() * x + y;
    }

    bool IsValid() const {
        if (x < 0 || y < 0
                || static_cast<unsigned>(x) >= heights[0].size()
                || static_cast<unsigned>(y) >= heights.size()) {
            return false;
        }
        return true;
    }

    int GetHeight() const {
        return heights[y][x];
    }

    bool operator==(const Point& other) const {
        return x == other.x && y == other.y && &heights == &other.heights;
    }
};

constexpr int allowed_directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool IsTherePath(const Point& from, const Point& to, int effort,
                 std::vector<bool>& not_allowed_points) {
    if (from == to) {
        return true;
    }
    not_allowed_points[from.GetIdx()] = true;
    for (auto& direction : allowed_directions) {
        Point next(from.x + direction[0], from.y + direction[1], from.heights);
        if (next.IsValid()
                && std::abs(next.GetHeight() - from.GetHeight()) <= effort
                && !not_allowed_points[next.GetIdx()]
                && IsTherePath(next, to, effort, not_allowed_points)) {
            return true;
        }
    }
    return false;
}

int GetMinEffort(const std::vector<std::vector<int>>& heights) {
    Point finish(heights[0].size() - 1, heights.size() - 1, heights);
    int left = 0;
    int right = 1'000'000;
    while (left < right) {
        int mid = left + (right - left) / 2;
        std::vector<bool> not_allowed_points(heights.size() * heights[0].size(),
                                             false);
        if (IsTherePath(Point(0, 0, heights), finish, mid, not_allowed_points)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

using std::vector;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        return GetMinEffort(heights);
    }
};
