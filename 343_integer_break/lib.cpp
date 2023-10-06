#include <cmath>

int GetMaxProduct(int n) {
    if (n <= 3) {
        return n - 1;
    }
    switch(n % 3) {
    case 0:
        return std::pow(3, n / 3);
    case 1:
        return 4 * std::pow(3, n / 3 - 1);
    case 2:
        return 2 * std::pow(3, n / 3);
    default:
        break;
    }
    return 0;
}

class Solution {
public:
    int integerBreak(int n) {
        return GetMaxProduct(n);
    }
};
