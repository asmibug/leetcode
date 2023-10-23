#include <bit>
#include <climits>
#include <cmath>

bool IsPowerOf4C20(int n) {
    return (n > 0 && ((n - 1) & n) == 0
            && std::countr_zero(static_cast<unsigned>(n)) % 2 == 0);
}

bool IsPowerOf4Log(int n) {
    if (n <= 0) {
        return false;
    }
    float half_log = 0.5f * std::log2f(n);
    return (half_log - static_cast<int>(half_log)) < 1e-5f;
}

bool IsPowerOf4Math(int n) {
    return n > 0 && ((n - 1) & n) == 0 && n % 3 == 1;
}

constexpr int GetMask(int step) {
    int mask = 0;
    for (unsigned i = 1 + step; i < sizeof(int) * CHAR_BIT; i += step) {
        mask |= 1;
        mask <<= step;
    }
    mask |= 1;
    return mask;
}

bool IsPowerOf4Mask(int n) {
    constexpr const int mask = GetMask(2);
    return n > 0 && ((n - 1) & n) == 0 && (mask & n);
}

class Solution {
public:
    bool isPowerOfFour(int n) {
        return IsPowerOf4Math(n);    
    }
};
