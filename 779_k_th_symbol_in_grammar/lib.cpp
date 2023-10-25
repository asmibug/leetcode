#include <bitset>

int GetKthOfNIterative(int n, int k) {
    if (n <= 1) {
        return 0;
    }
    --k;
    int pos = 1 << (n - 2);
    int cur = 0;
    for (; pos; pos >>= 1) {
        cur = (pos & k) ^ (cur >> 1);
    }
    return cur;
}

int GetKthOfNMath(int, int k) {
    return std::bitset<32>(k - 1).count() % 2;
}

class Solution {
public:
    int kthGrammar(int n, int k) {
        return GetKthOfNMath(n, k);
    }
};
