#include <algorithm>  // std::max std::max_element std::min std::min_element
    // std::sort std::swap
#include <climits>  // INT_MAX
#include <functional>  // std::greater
#include <queue>  // std::priority_queue
#include <vector>  // std::vector

namespace {
    int MinBuildTimeRecrusive(const std::vector<int>& blocks,
                              int split,
                              int blocks_left,
                              int workers,
                              std::vector<std::vector<int>>& memo) {
        if (blocks_left == 0) {
            return 0;
        }
        if (workers == 0) {
            return INT_MAX;
        }
        workers = std::min(blocks_left, workers);
        if (blocks_left == workers) {
            return blocks[blocks_left - 1];
        }
        if (memo[blocks_left][workers]) {
            return memo[blocks_left][workers];
        }
        int t_build = std::max(blocks[blocks_left - 1], MinBuildTimeRecrusive(
            blocks, split, blocks_left - 1, workers - 1, memo));
        int t_split = split + MinBuildTimeRecrusive(
            blocks, split, blocks_left, 2 * workers, memo);
        int time = std::min(t_build, t_split);
        memo[blocks_left][workers] = time;
        return time;
    }
}

int MinBuildTimeWithRecursion(std::vector<int> blocks, int split) {
    std::sort(blocks.begin(), blocks.end());
    std::vector<std::vector<int>> memo(blocks.size() + 1,
                                       std::vector<int>(blocks.size() + 1));
    return MinBuildTimeRecrusive(blocks, split, blocks.size(), 1, memo);
}

int MinBuildTimeDynamic(std::vector<int> blocks, int split) {
    int n = blocks.size();
    std::sort(blocks.begin(), blocks.end());
    std::vector<int> time_for_workers_num(n + 1);
    for (int blocks_num = 1; blocks_num <= n; ++blocks_num) {
        std::vector<int> new_times(n + 1);
        new_times[0] = INT_MAX;
        new_times[blocks_num] = blocks[blocks_num - 1];
        for (int workers_num = blocks_num - 1; workers_num > 0; --workers_num) {
            int time_if_work = std::max(blocks[blocks_num - 1],
                                        time_for_workers_num[workers_num - 1]);
            int workers_if_split = std::min(blocks_num, 2 * workers_num);
            int time_if_split = split + new_times[workers_if_split];
            new_times[workers_num] = std::min(time_if_work, time_if_split);
        }
        std::swap(time_for_workers_num, new_times);
    }
    return time_for_workers_num[1];
}

int MinBuildTimePriority(const std::vector<int>& blocks, int split) {
    // min-queue
    std::priority_queue merged_blocks(blocks.begin(), blocks.end(),
                                      std::greater<int>());
    while (merged_blocks.size() > 1) {
        int first = merged_blocks.top();
        merged_blocks.pop();
        int second = merged_blocks.top();
        merged_blocks.pop();
        merged_blocks.push(split + std::max(first, second));
    }
    return merged_blocks.top();
}

namespace {
    bool IsBuildPossible(const std::vector<int>& blocks, int split, int time) {
        int workers = 1;
        for (int i = blocks.size(); i > 0; --i) {
            if (workers == 0) {
                return false;
            }
            while (blocks[i - 1] + split <= time) {
                workers *= 2;
                time -= split;
                if (workers >= i) {
                    return true;
                }
            }
            --workers;
        }
        return true;
    }
}

int MinBuildTimeBinSearch(std::vector<int> blocks, int split) {
    std::sort(blocks.begin(), blocks.end());
    int left_time = blocks.back();
    int right_time = split * blocks.size() + blocks.back();
    while (left_time < right_time) {
        int mid_time = left_time + (right_time - left_time) / 2;
        if (IsBuildPossible(blocks, split, mid_time)) {
            right_time = mid_time;
        } else {
            left_time = mid_time + 1;
        }
    }
    return left_time;
}

using std::vector;

class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        return MinBuildTimeBinSearch(blocks, split);
    }
};

///////////////////////////////////////////////////////////////////////////////

#include "acutest.h"  // TEST_CHECK TEST_LIST TEST_MSG

#define CHECK_MinBuildTime(func, expected, blocks, split) do { \
    int t; \
    TEST_CHECK(expected == (t = func(blocks, split))); \
    TEST_MSG("Function returned %d", t); \
} while (0)

namespace {
    void TestOne() {
        CHECK_MinBuildTime(MinBuildTimeWithRecursion, 7, std::vector<int>{7}, 1);
    }

    void TestTwo() {
        CHECK_MinBuildTime(MinBuildTimeWithRecursion, 8,
                        (std::vector<int>{6, 7}), 1);
    }

    void TestThree() {
        CHECK_MinBuildTime(MinBuildTimeWithRecursion, 8,
                        (std::vector<int>{5, 6, 7}), 1);
    }

    void TestOneDynamic() {
        CHECK_MinBuildTime(MinBuildTimeDynamic, 7, std::vector<int>{7}, 1);
    }

    void TestTwoDynamic() {
        CHECK_MinBuildTime(MinBuildTimeDynamic, 8, (std::vector<int>{6, 7}), 1);
    }

    void TestThreeDynamic() {
        CHECK_MinBuildTime(MinBuildTimeDynamic, 8, (std::vector<int>{5, 6, 7}), 1);
    }

    void TestOnePriority() {
        CHECK_MinBuildTime(MinBuildTimePriority, 7, std::vector<int>{7}, 1);
    }

    void TestTwoPriority() {
        CHECK_MinBuildTime(MinBuildTimePriority, 8, (std::vector<int>{6, 7}), 1);
    }

    void TestThreePriority() {
        CHECK_MinBuildTime(MinBuildTimePriority, 8, (std::vector<int>{5, 6, 7}), 1);
    }

    void TestOneBinSearch() {
        CHECK_MinBuildTime(MinBuildTimeBinSearch, 7, std::vector<int>{7}, 1);
    }

    void TestTwoBinSearch() {
        CHECK_MinBuildTime(MinBuildTimeBinSearch, 8, (std::vector<int>{6, 7}), 1);
    }

    void TestThreeBinSearch() {
        CHECK_MinBuildTime(MinBuildTimeBinSearch, 8, (std::vector<int>{5, 6, 7}), 1);
    }
}

TEST_LIST = {
    {"test one block", TestOne},
    {"test two blocks", TestTwo},
    {"test three blocks", TestThree},
    {"test one block, dynamic algorithm", TestOneDynamic},
    {"test two blocks, dynamic algorithm", TestTwoDynamic},
    {"test three blocks, dynamic algorithm", TestThreeDynamic},
    {"test one block, priority algorithm", TestOnePriority},
    {"test two blocks, priority algorithm", TestTwoPriority},
    {"test three blocks, priority algorithm", TestThreePriority},
    {"test one block, binary search algorithm", TestOneBinSearch},
    {"test two blocks, binary search algorithm", TestTwoBinSearch},
    {"test three blocks, binary search algorithm", TestThreeBinSearch},
    {NULL, NULL}
};
