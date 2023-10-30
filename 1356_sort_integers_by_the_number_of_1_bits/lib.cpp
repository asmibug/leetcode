#include <algorithm>
#include <bitset>
#include <climits>
#include <type_traits>
#include <vector>

std::vector<int> SortByBits(std::vector<int>& arr) {
    std::ranges::sort(arr, [](int x, int y) {
        static_assert(std::is_same_v<decltype(x), decltype(y)>);
        constexpr int bits = sizeof(x) * CHAR_BIT;
        int bits_x = std::bitset<bits>(x).count();
        int bits_y = std::bitset<bits>(y).count();
        if (bits_x == bits_y) {
            return x < y;
        }
        return bits_x < bits_y;
    });
    return arr;
}

std::vector<int> SortByBits(std::vector<int>&& arr) {
    return SortByBits(arr);
}

using std::vector;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        return SortByBits(arr);
    }
};
