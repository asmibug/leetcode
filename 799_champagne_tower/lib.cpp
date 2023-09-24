#include <algorithm>
#include <vector>

double GetAmount(int poured, int row_idx, int glass_idx) {
    std::vector<double> current_amount = {static_cast<double>(poured)};
    for (int i = 0; i < row_idx; ++i) {
        std::vector<double> new_amount = {
            std::max(0., current_amount[0] - 1) / 2};
        for (int j = 1; j < i + 1; ++j) {
            new_amount.push_back((std::max(0., current_amount[j - 1] - 1)
                                  + std::max(0., current_amount[j] - 1)
                                  ) / 2);
        }
        new_amount.push_back(std::max(0., current_amount.back() - 1) / 2);
        std::swap(current_amount, new_amount);
    }
    return std::min(1., current_amount[glass_idx]);
}

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        return GetAmount(poured, query_row, query_glass);
    }
};
