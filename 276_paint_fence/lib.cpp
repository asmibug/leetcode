/**
 * Approach: dynamic programming
 * Calculate function f(n, same_as_previous):
 * f(n, 0) = (k - 1) * (f(n - 1, 0) + f(n - 1, 1))
 * f(n, 1) = f(n - 1, 0)
 * 
 * Coding approaches:
 * 1) Recursive with memoization
 * 2) Iterative
*/

#include <functional>
#include <vector>

int GetNumWaysRecursiveLambda1(int n, int k) {
    std::vector memo(n, 0);
    memo[0] = k;
    std::function<int(int)> f = [k, &memo, &f](int n) {
        if (n <= 0) {
            return 0;
        }
        if (memo[n - 1]) {
            return memo[n - 1];
        }
        return memo[n - 1] = (k - 1) * (f(n - 1) + f(n - 2));
    };
    return f(n) + f(n - 1);
}

int GetNumWaysRecursiveLambda2(int n, int k) {
    std::vector memo(n, 0);
    memo[0] = k;
    auto f = [k, &memo](const auto& f, int n) {
        if (n <= 0) {
            return 0;
        }
        if (memo[n - 1]) {
            return memo[n - 1];
        }
        return memo[n - 1] = (k - 1) * (f(f, n - 1) + f(f, n - 2));
    };
    return f(f, n) + f(f, n - 1);
}

int GetNumWaysIterative(int n, int k) {
    int num_if_same_as_prev = 0;
    int num_if_different = k;
    for (int i = 2; i <= n; ++i) {
        int new_num_if_different = (k - 1) * (num_if_same_as_prev
                                              + num_if_different);
        num_if_same_as_prev = num_if_different;
        num_if_different = new_num_if_different;
    }
    return num_if_same_as_prev + num_if_different;
}

class Solution {
public:
    int numWays(int n, int k) {
        return GetNumWaysIterative(n, k);
    }
};
