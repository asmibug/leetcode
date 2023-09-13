#include "lib.cpp"

#include <random>  // std::mt19937 std::uniform_int_distribution
#include <sstream>  // std::ostringstream

#include "utest.h"

#define INSERT_TEST(func) \
UTEST(func, UnitTests) { \
    EXPECT_EQ(1, func({0})); \
    EXPECT_EQ(2, func({0, 0})); \
    EXPECT_EQ(3, func({0, 1})); \
    EXPECT_EQ(3, func({1, 0})); \
    EXPECT_EQ(4, func({0, 1, 0})); \
    EXPECT_EQ(5, func({1, 0, 1})); \
    EXPECT_EQ(6, func({0, 1, 1, 0})); \
    EXPECT_EQ(7, func({0, 1, 1, 1, 0})); \
    EXPECT_EQ(5, func({1, 0, 2})); \
    EXPECT_EQ(4, func({1, 2, 2})); \
    EXPECT_EQ(47, func({1,2,3,5,4,3,2,1,4,3,2,1,3,2,1,1,2,3,4})); \
} \

INSERT_TEST(GetMinSumOfCandies)

INSERT_TEST(GetMinSumOfCandiesOnePass)

namespace {
    std::vector<int> GenerateRatings(int len, int min, int max) {
        std::vector<int> ratings;
        ratings.reserve(len);
        std::mt19937 gen;
        std::uniform_int_distribution distrib(min, max);
        for (int i = 0; i < len; ++i) {
            ratings.push_back(distrib(gen));
        }
        return ratings;
    }

    bool IsCostValid(const std::vector<int>& costs,
                    const std::vector<int>& ratings) {
        int n = costs.size();
        for (int i = 0; i < n; ++i) {
            if (costs[i] < 1) {
                return false;
            }
        }
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1] && costs[i] <= costs[i - 1]) {
                return false;
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            if (ratings[i] > ratings[i + 1] && costs[i] <= costs[i + 1]) {
                return false;
            }
        }
        return true;
    }

    constexpr int STRESS_TESTS_NUM = 10000;
}

UTEST(GetCost, StressTest) {
    for (int i = 0; i < STRESS_TESTS_NUM; ++i) {
        auto ratings = GenerateRatings(10, 0, 9);
        auto costs = GetCosts(ratings);
        std::ostringstream s;
        s << "\nratings: ";
        for (int r : ratings) {
            s << r << " ";
        }
        s << "\ncosts:   ";
        for (int c : costs) {
            s << c << " ";
        }
        EXPECT_TRUE_MSG(IsCostValid(costs, ratings), s.str().c_str());
    }
}

UTEST(GetMinSumOfCandiesOnePass, StressTest) {
    for (int i = 0; i < STRESS_TESTS_NUM; ++i) {
        auto ratings = GenerateRatings(10, 0, 9);
        EXPECT_EQ(GetMinSumOfCandies(ratings),
                  GetMinSumOfCandiesOnePass(ratings));
    }
}

UTEST_MAIN()
