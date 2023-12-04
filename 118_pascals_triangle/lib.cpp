/**
 * https://leetcode.com/problems/pascals-triangle/
 * 
 * Approach: just follow the definition of the Pascal's triangle
*/

#include <vector>  // std::vector

std::vector<std::vector<int>> GetPascalTriangle(int num_rows) {
    decltype(GetPascalTriangle(num_rows)) triangle = {{1}};
    for (int i = 1; i < num_rows; ++i) {
        triangle.push_back({1});
        for (int j = 1; j < i; ++j) {
            triangle[i].push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
        }
        triangle[i].push_back(1);
    }
    return triangle;
}

using std::vector;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        return GetPascalTriangle(numRows);
    }
};
