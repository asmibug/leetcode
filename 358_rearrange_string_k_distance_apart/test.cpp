#include "lib.cpp"

#include <algorithm>  // std::sort

#include "utest.h"

UTEST(Utest, CanaryTest) {
    EXPECT_TRUE(true);
}

namespace {
    bool IsValid(std::string result, bool is_possible,
                 std::string s, int min_distance) {
        if (!is_possible) {
            return result == "";
        }
        for (unsigned i = 0; i < result.size(); ++i) {
            for (unsigned j = i + 1;
                 j < result.size() && j < i + min_distance;
                 ++j) {
                if (result[i] == result[j]) {
                    return false;
                }
            }
        }
        std::sort(result.begin(), result.end());
        std::sort(s.begin(), s.end());
        return result == s;
    }
}

#define INSERT_TEST(func, s, min_distance, is_possible) \
UTEST(func, s ## _ ## min_distance ## _ ## is_possible) { \
    std::string input = #s; \
    int distance = min_distance; \
    std::string result = func(input, distance); \
    EXPECT_TRUE_MSG(IsValid(result, is_possible, input, distance), \
                    result.c_str()); \
} \

// TODO: test result validity, not result itself

INSERT_TEST(RearrangeStringHeap, a, 10, true)
INSERT_TEST(RearrangeStringHeap, aa, 0, true)
INSERT_TEST(RearrangeStringHeap, aa, 1, true)
INSERT_TEST(RearrangeStringHeap, aa, 2, false)
INSERT_TEST(RearrangeStringHeap, ab, 10, true)
INSERT_TEST(RearrangeStringHeap, aab, 2, true)
INSERT_TEST(RearrangeStringHeap, aab, 3, false)
INSERT_TEST(RearrangeStringHeap, aabbcc, 2, true)
INSERT_TEST(RearrangeStringHeap, aabbcc, 4, false)
INSERT_TEST(RearrangeStringHeap, abcdabcdabdeac, 4, true)
INSERT_TEST(RearrangeStringHeap, aaaaabbbbcccdddeeefffggghhh, 6, true)

INSERT_TEST(RearrangeStringGreedy, a, 10, true)
INSERT_TEST(RearrangeStringGreedy, aa, 0, true)
INSERT_TEST(RearrangeStringGreedy, aa, 1, true)
INSERT_TEST(RearrangeStringGreedy, aa, 2, false)
INSERT_TEST(RearrangeStringGreedy, ab, 10, true)
INSERT_TEST(RearrangeStringGreedy, aab, 2, true)
INSERT_TEST(RearrangeStringGreedy, aab, 3, false)
INSERT_TEST(RearrangeStringGreedy, aabbcc, 2, true)
INSERT_TEST(RearrangeStringGreedy, aabbcc, 4, false)
INSERT_TEST(RearrangeStringGreedy, abcdabcdabdeac, 4, true)
INSERT_TEST(RearrangeStringGreedy, aaaaabbbbcccdddeeefffggghhh, 6, true)

UTEST_MAIN();
