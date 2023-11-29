/**
 * https://leetcode.com/problems/number-of-1-bits/
 * 
 * Approaches:
 * 1) Check all powers of 2
 * 2) Brian Kernighan way
 * 3) Compiler's __builtin_popcount() or C++11 std::bitset().count()
 *    or C++20 popcount()
*/

#include <bitset>
#include <cstdint>

int CountOneBitsIteratively(uint32_t n) {
    int res = 0;
    while (n) {
        res += n & 1;
        n >>= 1;
    }
    return res;
}

int CountOneBitsBrianKernighan(uint32_t n) {
    int res = 0;
    while (n) {
        ++res;
        n &= n - 1;
    }
    return res;
}

int CountOneBitsBitset(uint32_t n) {
    return std::bitset<32>(n).count();
}

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return CountOneBitsBrianKernighan(n);
    }
};
