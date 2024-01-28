/**
 * At each step we need to merge two smallest items
 * 
 * Approaches:
 * 1) Heap
 * 2) Sort
*/

#include <algorithm>
#include <climits>
#include <functional>
#include <queue>
#include <vector>

int GetMinMergeTimeHeap(std::vector<int>&& costs) {
    std::priority_queue heap(std::greater<int>(), std::move(costs));
    int res = 0;
    while (heap.size() > 1) {
        int one = heap.top();
        heap.pop();
        int two = heap.top();
        heap.pop();
        heap.push(one + two);
        res += one + two;
    }
    return res;
}

int GetMinMergeTimeSort(std::vector<int>& costs) {
    if (costs.size() <= 1) {
        return 0;
    }
    std::ranges::sort(costs);
    int res = 0;
    std::queue<int> merged;
    for (auto it = costs.begin(); it != costs.end() || merged.size() > 1;) {
        int mins[2];
        for (int& v : mins) {
            if (merged.empty() || (it != costs.end() && *it < merged.front())) {
                v = *it++;
            } else {
                v = merged.front();
                merged.pop();
            }
        }
        merged.push(mins[0] + mins[1]);
        res += mins[0] + mins[1];
    }
    return res;
}

int GetMinMergeTimeSort(std::vector<int>&& costs) {
    return GetMinMergeTimeSort(costs);
}

int GetMinMergeTimeSortOptimized(std::vector<int>& costs) {
    int n = costs.size();
    if (n <= 1) {
        return 0;
    }
    std::ranges::sort(costs);
    int res = 0;
    int queue_head = 0;
    int queue_tail = 0;
    for (int i = 0; n - i + queue_tail - queue_head > 1;) {
        int sum = 0;
        for (int j = 0; j < 2; ++j) {
            if (i == n || (queue_head != queue_tail
                           && costs[queue_head] < costs[i])) {
                sum += costs[queue_head++];
            } else {
                sum += costs[i++];
            }
        }
        costs[queue_tail++] = sum;
        res += sum;
    }
    return res;
}

int GetMinMergeTimeSortOptimized(std::vector<int>&& costs) {
    return GetMinMergeTimeSortOptimized(costs);
}

using std::vector;

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        return GetMinMergeTimeSortOptimized(sticks);
    }
};
