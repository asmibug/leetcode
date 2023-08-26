#include <algorithm>  // std::max std::sort std::upper_bound
#include <vector>  // std::vector

using std::vector;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        std::sort(pairs.begin(), pairs.end(), cmp);
        vector<int> number_of_greater_pairs;
        for (auto it = pairs.begin(); it != pairs.end(); ++it) {
            number_of_greater_pairs.push_back(
                pairs.end() - std::upper_bound(it, pairs.end(), (*it)[1], cmp1)
            );
        }
        vector<int> results = {0};
        for (int i = 1; i <= n; ++i) {
            results.push_back(std::max(
                1 + results[number_of_greater_pairs[n - i]],
                results.back()
            ));
        }

        return results.back();
    }

private:
    static bool cmp(const vector<int>& left, const vector<int>& right) {
        return left[0] < right[0];
    }

    static bool cmp1(int left, const vector<int>& right) {
        return left < right[0];
    }
};

#ifndef TEST
int main() {
    return 0;
}
#endif

///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>  // std::cout std::endl

static inline bool checkFindLongestChain(std::vector<std::vector<int>> pairs,
                                        int expected) {
    return Solution().findLongestChain(pairs) == expected;
}

static void test() {
    assert(checkFindLongestChain({{0, 1}}, 1));
    assert(checkFindLongestChain({{2, 3}, {0, 1}}, 2));
    assert(checkFindLongestChain({{1, 10}, {2, 3}, {4, 5}}, 2));
    assert(checkFindLongestChain({{7,9},{4,5},{7,9},{-7,-1},{0,10},{3,10},{3,6},{2,3}}, 4));
    std::cout << "ALL TESTS PASSED" << std::endl;
    
}

#ifdef TEST
int main() {
    test();
    return 0;
}
#endif
