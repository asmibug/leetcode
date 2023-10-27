#include <algorithm>
#include <string>
#include <vector>

std::string GetLongestPalindromeSimple(const std::string& s) {
    int n = s.size();
    int nn = 2 * n - 1;
    int max_radius = -1;
    int max_center = -1;
    for (int i = 0; i + max_radius + 1 < nn; ++i) {
        int radius = -(i % 2);  // make sure radius and i have the same parity
        do {
            radius += 2;
        } while (0 <= i - radius && i + radius < nn
                 && s[(i - radius) / 2] == s[(i + radius) / 2]);
        radius -= 2;
        if (radius > max_radius) {
            max_radius = radius;
            max_center = i;
        }
    }
    int left = (max_center - max_radius) / 2;
    int right = (max_center + max_radius) / 2;
    return s.substr(left, right - left + 1);
}

std::string GetLongestPalindromeManacher(const std::string& s) {
    int n = s.size();
    int nn = 2 * n - 1;
    int max_radius = -1;
    int max_center = -1;

    int border = 0;
    int center = 0;
    std::vector<int> radii;
    radii.reserve(nn);

    for (int i = 0; i + max_radius + 1 < nn; ++i) {
        int radius = (i < border
                      ? std::min(radii[center - (i - center)], border - i)
                      : -(i % 2)  // make sure radius and i have the same parity
                      );
        do {
            radius += 2;
        } while (0 <= i - radius && i + radius < nn
                 && s[(i - radius) / 2] == s[(i + radius) / 2]);
        radius -= 2;
        if (radius > max_radius) {
            max_radius = radius;
            max_center = i;
        }

        if (i + radius > border) {
            border = i + radius;
            center = i;
        }
        radii.push_back(radius);
    }
    int left = (max_center - max_radius) / 2;
    int right = (max_center + max_radius) / 2;
    return s.substr(left, right - left + 1);
}

using std::string;

class Solution {
public:
    string longestPalindrome(const string& s) {
        return GetLongestPalindromeManacher(s);
    }
};
