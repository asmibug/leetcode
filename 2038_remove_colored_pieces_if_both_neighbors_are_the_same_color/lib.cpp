#include <stdexcept>
#include <string>

bool IsAliceWinner(const std::string& colors) {
    int n = colors.size();
    int alice_moves = 0;
    int bob_moves = 0;
    int range_begin = 0;
    for (int i = 0; i <= n; ++i) {
        if (i == n || colors[i] != colors[range_begin]) {
            int moves = i - range_begin >= 3 ? i - range_begin - 2 : 0;
            switch (colors[range_begin]) {
            case 'A':
                alice_moves += moves;
                break;
            case 'B':
                bob_moves += moves;
                break;
            default:
                throw std::runtime_error("Unknown piece: "
                                         + colors[range_begin]);
            }
            range_begin = i;
        }
    }
    return alice_moves > bob_moves;
}

using std::string;

class Solution {
public:
    bool winnerOfGame(const string& colors) {
        return IsAliceWinner(colors);
    }
};
