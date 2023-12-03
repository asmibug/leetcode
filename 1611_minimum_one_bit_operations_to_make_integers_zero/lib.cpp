/**
 * https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
 * 
 * set_i = set_{i-1} + 1 + unset_{i-1}
 * unset_i = set_{i-1} + 1 + unset_{i-1}
 * set_i = unset_i = 2 set_{i-1} + 1 = 2 (set_{i-1} + 1) - 1
 * set_i + 1 = 2 (set_{i-1} + 1) = 2 * 2^{i-1} (set_0 + 1)
 * set_0 = 1
 * set_i = unset_i = 2^{i+1} - 1
 * 
 * Approach 1 (act according to the rules):
 * Leftmost set bit may be unset only by pattern 1100000.
 * If there is set bit right after the leftmost set bit,
 * then number of operations to unset: 1 + 2^{i-1+1} - 1 = 2^i,
 * where i is index of the leftmost set bit.
 * If there is no set bit right after the leftmost,
 * we need to move set bit to the required position.
 * To move set bit from position i - 1 to position i we need 2^i operations
 * 
 * Approach 2 (DP: zero leftmost bits first):
 * Let f(x, y) is minimum number of steps to get from state x to state y.
 * Then f(0, 2^i) = f(2^i, 0) = 2^{i+1} - 1.
 * Possible number of states to the right of the i-th bit is 2^i.
 * Therefore, according to the pigeonhole principle, to set i-th bit,
 * we need to pass through all 2^i states to the right of the i-th bit.
 * Therefore, if we try to unset the leftmost k-th bit of n,
 * we'll pass through the state n:
 * f(2^k, 0) = f(2^k, n) + f(n, 0).
 * And to get from n to 2^k we need to unset all bits except k:
 * f(n, 2^k) = f(n xor 2^k, 0).
 * Therefore, f(2^k, 0) = f(n xor 2^k, 0) + f(n, 0).
 * f(n, 0) = f(2^k, 0) - f(n xor 2^k, 0),
 * where k is the index of the leftmost set bit of n.
 * 
 * Approach 3 (DP: set rightmost bits first)
 * This approach based on the same idea as approach 2, but we move from right.
 * Let in n we have set bits at positions from right to left k_0, ..., k_l:
 * n = 2^{k_0} + 2^{k_1} + ... + 2^{k_l}.
 * Let n_i = 2^{k_0} + ... + 2^{k_i}.
 * f(0, 2^{k_i}) = f(0, n_i) + f(n_i, 2^{k_i}) = f(0, n_i) + f(n_{i-1}, 0)
 * f(0, n_i) = f(0, 2^{k_i}) - f(n_{i-1}, 0)
 * f(0, n_0) = f(0, 2^{k_0})
 * f(0, n) = f(n_{k_l})
 * 
 * Approach 4 (Similar to the approach 1, Reverse Gray code)
 * Let k is the index of the most significant set bit.
 * To zero k bit we need to get pattern 1100000,
 * and after that we can zero the rest with 2^k operations.
 * f(n, 0) = f(n xor 2^k xor 2^{k-1}) + 2^k
 * Therefore, each bit of f(n, 0) is the cumulative xor of previous bits,
 * just like in the Gray code to number conversion
 * 
 * Approach 5 (Dynamic Programming)
 * GetOperationsToZero(n) = GetOperationsToOneAt(k - 1, (1 << k) ^ n) + (1 << k)
 * GetOperationsToOneAt(k, n) = ((1 << k) & n
 *                               ? GetOperationsToZero((1 << k) ^ n)
 *                               : GetOperationsToOneAt(k - 1, n) + (1 << k))
*/

#include <bit>
#include <climits>

int GetMinOperationsApproach1Recursive(unsigned n) {
    if (n == 0) {
        return 0;
    }
    unsigned left_set_bit = 1 << (31 - std::countl_zero(n));
    if (left_set_bit == n) {
        return (left_set_bit << 1) - 1;
    }
    unsigned operations = 0;
    n ^= left_set_bit;
    do {
        operations += left_set_bit;
        left_set_bit >>= 1;
    } while ((left_set_bit & n) == 0);
    n ^= left_set_bit;
    operations += GetMinOperationsApproach1Recursive(n);
    return operations;
}

int GetMinOperationsApproach2Iterative(unsigned n) {
    unsigned left_set_bit = 1;
    while (left_set_bit << 1 <= n) {
        left_set_bit <<= 1;
    }

    unsigned operations = 0;
    int sign = 1;
    while (n) {
        while ((n & left_set_bit) == 0) {
            left_set_bit >>= 1;
        }
        operations += sign * ((left_set_bit << 1) - 1);
        sign *= -1;
        n ^= left_set_bit;
    }
    return operations;
}

int GetMinOperationsApproach3Iterative(unsigned n) {
    unsigned operations = 0;
    while (n) {
        operations = (n ^ (n - 1)) - operations;
        n &= n - 1;
    }
    return operations;
}

int GetMinOperationsReverseGray(unsigned n) {
    for (unsigned mask = n >> 1; mask; mask >>= 1) {
        n ^= mask;
    }
    return n;
}

int GetMostSignificantBitIndex(unsigned n) {
    return sizeof(n) * CHAR_BIT - 1 - std::countl_zero(n);
}

int GetOperationsToOneAt(int k, unsigned n);

int GetOperationsToZero(unsigned n) {
    if (n == 0) {
        return 0;
    }
    int k = GetMostSignificantBitIndex(n);
    return GetOperationsToOneAt(k - 1, (1 << k) ^ n) + (1 << k);
}

int GetOperationsToOneAt(int k, unsigned n) {
    if (k < 0) {
        return 0;
    }
    if ((1 << k) & n) {
        return GetOperationsToZero((1 << k) ^ n);
    }
    return GetOperationsToOneAt(k - 1, n) + (1 << k);
}

int GetMinOperationsDP(unsigned n) {
    return GetOperationsToZero(n);
}

class Solution {
public:
    int minimumOneBitOperations(int n) {
        return GetMinOperationsReverseGray(n);
    }
};
