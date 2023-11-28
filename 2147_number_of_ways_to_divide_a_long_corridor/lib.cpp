/**
 * https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/
 * 
 * Solution approaches:
 * 1) Divide the corridor to pairs and multiply number of ways to place borders
 *    between each pair (45ms)
 * 2) Dynamic programming (53ms)
 * 
 * Dynamic programming variants:
 * 1) Top-down (recursive) with memoization
 * 2) Bottom-up (iterative)
*/

#include <string>

constexpr int kMod = 1e9 + 7;

int GetNumberOfWaysByMultiplication(const std::string& corridor) {
    int n = corridor.size();
    int chairs_count = 0;
    int right_border = n;
    for (; right_border > 0 && chairs_count < 2; --right_border) {
        chairs_count += corridor[right_border - 1] == 'S';
    }
    if (chairs_count < 2) {
        return 0;
    }
    int res = 1;
    int i = 0;
    while (i < right_border) {
        chairs_count = 0;
        for (; i < right_border && chairs_count < 2; ++i) {
            chairs_count += corridor[i] == 'S';
        }
        int plants_count = 0;
        for (; i < right_border && corridor[i] == 'P'; ++i) {
            ++plants_count;
        }
        res = (res * (plants_count + 1LL)) % kMod;
    }
    return (chairs_count != 1) * res;
}

int GetNumberOfWaysByDP(const std::string& corridor) {
    struct {
        int s[3];
    } state = {1, 0, 0};
    for (char c : corridor) {
        bool is_seat = c == 'S';
        state = {(state.s[0] * (1 - is_seat) + state.s[2 - is_seat]) % kMod,
                 state.s[1 - is_seat],
                 state.s[2 - is_seat]};
    }
    return state.s[2];
}

using std::string;

class Solution {
public:
    int numberOfWays(const string& corridor) {
        return GetNumberOfWaysByMultiplication(corridor);
    }
};
