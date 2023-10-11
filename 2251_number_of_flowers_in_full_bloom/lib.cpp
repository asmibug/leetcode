#include <algorithm>
#include <compare>
#include <functional>
#include <queue>
#include <stdexcept>
#include <unordered_map>
#include <vector>

enum class PointType {
    begin,
    person,
    end,
};

struct Point {
    int x;
    PointType t;

    friend std::strong_ordering operator<=>(const Point& a, const Point& b) {
        return a.x <=> b.x != 0 ? a.x <=> b.x : a.t <=> b.t;
    }
};

std::vector<int> GetNumSortEnds(
    const std::vector<std::vector<int>>& flower_intervals,
    const std::vector<int>& people
) {
    std::vector<Point> points;
    for (const auto& interval : flower_intervals) {
        points.push_back({interval[0], PointType::begin});
        points.push_back({interval[1], PointType::end});
    }
    std::unordered_map<int, std::vector<int>> time_to_people;
    for (int i = 0; i < static_cast<int>(people.size()); ++i) {
        if (!time_to_people.contains(people[i])) {
            points.push_back({people[i], PointType::person});
        }
        time_to_people[people[i]].push_back(i);
    }
    std::sort(points.begin(), points.end());
    
    std::vector<int> res(people.size());
    int num_blooming = 0;
    for (const auto& point : points) {
        switch (point.t) {
        case PointType::begin:
            ++num_blooming;
            break;
        case PointType::person:
            for (int idx : time_to_people[point.x]) {
                res[idx] = num_blooming;
            }
            break;
        case PointType::end:
            --num_blooming;
            break;
        default:
            throw std::runtime_error(
                "Unknown PointType: "
                + std::to_string(static_cast<int>(point.t)));
        }
    }
    return res;
}

std::vector<int> GetNumHeap(
    std::vector<std::vector<int>>& flower_intervals,
    const std::vector<int>& people
) {
    std::sort(flower_intervals.begin(), flower_intervals.end());
    std::vector<int> people_indices;
    people_indices.reserve(people.size());
    for (auto i = 0u; i < people.size(); ++i) {
        people_indices.push_back(i);
    }
    std::sort(people_indices.begin(), people_indices.end(),
              [&people](int i, int j) {
                  return people[i] < people[j];
              });
    
    std::vector<int> res(people.size());
    auto started = 0u;
    std::priority_queue<int, std::vector<int>, std::greater<int>> right_ends;
    for (int idx : people_indices) {
        while (started < flower_intervals.size()
               && flower_intervals[started][0] <= people[idx]) {
            right_ends.push(flower_intervals[started][1]);
            ++started;
        }
        while (!right_ends.empty() && right_ends.top() < people[idx]) {
            right_ends.pop();
        }
        res[idx] = right_ends.size();
    }
    return res;
}

std::vector<int> GetNumHeap(
    std::vector<std::vector<int>>&& flower_intervals,
    const std::vector<int>& people
) {
    return GetNumHeap(flower_intervals, people);
}

std::vector<int> GetNumTwoPointers(
    const std::vector<std::vector<int>>& intervals,
    const std::vector<int>& times
) {
    int n = intervals.size();
    int m = times.size();
    std::vector<int> begins;
    begins.reserve(n);
    std::vector<int> ends;
    ends.reserve(n);
    std::vector<int> time_indices;
    time_indices.reserve(m);
    for (const auto& interval : intervals) {
        begins.push_back(interval[0]);
        ends.push_back(interval[1]);  // TODO
    }
    for (int i = 0; i < m; ++i) {
        time_indices.push_back(i);
    }
    std::sort(begins.begin(), begins.end());
    std::sort(ends.begin(), ends.end());
    std::sort(time_indices.begin(), time_indices.end(), [&times](int i, int j) {
        return times[i] < times[j];
    });

    std::vector<int> res(m);
    int started = 0;
    int stopped = 0;
    for (int idx : time_indices) {
        auto time = times[idx];
        while (started < n && begins[started] <= time) {
            ++started;
        }
        while (stopped < n && ends[stopped] < time) {
            ++stopped;
        }
        res[idx] = started - stopped;
    }
    return res;
}

using std::vector;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers,
                                 vector<int>& people) {
        return GetNumTwoPointers(flowers, people);
    }
};
