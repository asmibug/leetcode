#include <algorithm>

int GetMaxNumberOfOnes(int width, int height, int side_length, int max_ones) {
    int m = height;
    int n = width;
    int k = side_length;
    int l = max_ones;

    int m_1 = m / k;
    int n_1 = n / k;
    int m_2 = m % k;
    int n_2 = n % k;

    int c_1, k_1, c_2, k_2;
    if (m_1 < n_1) {
        c_1 = n_1;
        k_1 = m_2;
        c_2 = m_1;
        k_2 = n_2;
    } else {
        c_1 = m_1;
        k_1 = n_2;
        c_2 = n_1;
        k_2 = m_2;
    }

    int l_0 = std::min(m_2 * n_2, l);
    int l_1 = std::min(k_1 * k, l);
    int l_2 = std::min(k_2 * k - l_0, l - l_1) + l_0;

    return l * m_1 * n_1 + l_0 + l_1 * c_1 + l_2 * c_2;
}

class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        return GetMaxNumberOfOnes(width, height, sideLength, maxOnes);
    }
};
