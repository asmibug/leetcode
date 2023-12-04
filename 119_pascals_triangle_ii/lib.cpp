/**
 * https://leetcode.com/problems/pascals-triangle-ii/
 * 
 * Approaches:
 * 1) Calculate all rows
 * 2) Calculate only required row using C_n^k / C_n^{k-1} = (n - k + 1) / k
*/

#include <vector>

std::vector<int> GetRowIteration(int row_index) {
    std::vector<int> row(row_index + 1, 1);
    for (int i = 0; i < row_index; ++i) {
        for (int j = i; j > 0; --j) {
            row[j] += row[j - 1];
        }
    }
    return row;
}

std::vector<int> GetRowMath(int row_index) {
    std::vector<int> row = {1};
    row.reserve(row_index + 1);
    for (int i = 0; i < row_index; ++i) {
        row.push_back(row.back() * 1ull * (row_index - i) / (i + 1));
    }
    return row;
}

using std::vector;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        return GetRowMath(rowIndex);
    }
};
