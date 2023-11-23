#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>

std::vector<int> GetDiagonalOrderTraverse(
        const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    std::vector<int> res;
    int max_columns = 0;
    for (int k = 0; k < n; ++k) {
        max_columns = std::max<int>(max_columns, matrix[k].size());
        for (int i = k; i >= 0; --i) {
            int j = k - i;
            if (j < static_cast<int>(matrix[i].size())) {
                res.push_back(matrix[i][j]);
            }
        }
    }
    for (int k = 1; k < max_columns; ++k) {
        for (int j = k; j < max_columns; ++j) {
            int i = n - 1 - (j - k);
            if (i < 0) {
                break;
            }
            if (j < static_cast<int>(matrix[i].size())) {
                res.push_back(matrix[i][j]);
            }
        }
    }
    return res;
}

std::vector<int> GetDiagonalOrderSort(
        const std::vector<std::vector<int>>& matrix) {
    std::vector<std::tuple<unsigned, unsigned, int>> values_with_order;
    for (auto i = 0u; i < matrix.size(); ++i) {
        for (auto j = 0u; j < matrix[i].size(); ++j) {
            values_with_order.emplace_back(i + j, j, matrix[i][j]);
        }
    }
    std::ranges::sort(values_with_order);
    std::vector<int> res;
    for (auto [ij, j, val] : values_with_order) {
        res.push_back(val);
    }
    return res;
}

std::vector<int> GetDiagonalOrderVect(
        const std::vector<std::vector<int>>& matrix) {
    std::vector<std::vector<int>> values(matrix.size());
    for (auto i = matrix.size() - 1; i + 1 > 0; --i) {
        for (auto j = 0u; j < matrix[i].size(); ++j) {
            if (values.size() == i + j) {
                values.push_back({matrix[i][j]});
            } else {
                values[i + j].push_back(matrix[i][j]);
            }
        }
    }
    std::vector<int> res;
    for (const auto& range : values) {
        for (int x : range) {
            res.push_back(x);
        }
    }
    return res;
}

std::vector<int> GetDiagonalOrderBfs(
        const std::vector<std::vector<int>>& matrix) {
    std::vector<int> res;
    auto ij = 0u;
    std::queue<unsigned> j_indices;
    j_indices.push(0);
    while(!j_indices.empty()) {
        int diag_elements_num = j_indices.size();
        if (ij + 1 < matrix.size()) {
            j_indices.push(0);
        }
        for (int k = 0; k < diag_elements_num; ++k) {
            auto j = j_indices.front();
            j_indices.pop();
            auto i = ij - j;
            if (j + 1 < matrix[i].size()) {
                j_indices.push(j + 1);
            }
            res.push_back(matrix[i][j]);
        }
        ++ij;
    }
    return res;
}

std::vector<int> GetDiagonalOrderBfsInplace(
        const std::vector<std::vector<int>>& matrix) {
    std::vector<int> res;  // result and queue for j indices simultaneously
    unsigned processed = 0;
    unsigned ij = 0;
    res.push_back(0);
    while (processed < res.size()) {
        unsigned diag_elements_num = res.size() - processed;
        if (ij + 1 < matrix.size()) {
            res.push_back(0);
        }
        for (unsigned k = 0; k < diag_elements_num; ++k) {
            unsigned j = res[processed];
            unsigned i = ij - j;
            res[processed] = matrix[i][j];
            ++processed;
            if (j + 1 < matrix[i].size()) {
                res.push_back(j + 1);
            }
        }
        ++ij;
    }
    return res;
}

using std::vector;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        return GetDiagonalOrderBfsInplace(nums);
    }
};
