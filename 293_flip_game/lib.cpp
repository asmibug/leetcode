/**
 * Approach: find, copy and replace
*/

#include <string>
#include <vector>

std::vector<std::string> GeneratePossibleMoves(const std::string& state) {
    int n = state.size();

    int possible_moves_count = 0;
    for (int i = 1; i < n; ++i) {
        if (state[i] == '+' && state[i - 1] == '+') {
            ++possible_moves_count;
        }
    }
    
    std::vector<std::string> res;
    res.reserve(possible_moves_count);
    for (unsigned i = 1; i < state.size(); ++i) {
        if (state[i] == '+' && state[i - 1] == '+') {
            res.push_back(state);
            res.back()[i] = res.back()[i - 1] = '-';
        }
    }
    return res;
}

using std::string;
using std::vector;

class Solution {
public:
    vector<string> generatePossibleNextMoves(const string& currentState) {
        return GeneratePossibleMoves(currentState);
    }
};
