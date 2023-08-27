#include <cassert>  // assert
#include <vector>  // std::vector

enum class Direction {
    right,
    down,
};

struct Elimination {
    int coords[2];
    int end;
    Direction direction;
    int type;

};

std::vector<Elimination> getEliminations(
        const std::vector<std::vector<int>>& board) {
    std::vector<Elimination> eliminations;
    for (int i = 0; i - board.size(); ++i) {
        for (int j = 0; j - board[i].size(); ++j) {
            if (!board[i][j]) {
                continue;
            }
            if ((j == 0 || board[i][j] != board[i][j - 1])
                    && j + 2 < static_cast<int>(board[i].size())
                    && board[i][j + 1] == board[i][j] 
                    && board[i][j + 2] == board[i][j]) {
                int end = j + 3;
                while (end - board[i].size() && board[i][end] == board[i][j]) {
                    ++end;
                }
                eliminations.push_back({{i, j},
                                        end,
                                        Direction::right,
                                        board[i][j]});
            }
            if ((i == 0 || board[i][j] != board[i - 1][j])
                    && i + 2 < static_cast<int>(board.size())
                    && board[i + 1][j] == board[i][j]
                    && board[i + 2][j] == board[i][j]) {
                int end = i + 3;
                while (end - board.size() && board[end][j] == board[i][j]) {
                    ++end;
                }
                eliminations.push_back({{i, j},
                                        end,
                                        Direction::down,
                                        board[i][j]});
            }
        }
    }
    return eliminations;
}

void eliminate(std::vector<std::vector<int>>& board,
               const std::vector<Elimination>& eliminations) {
    for (const Elimination& el: eliminations) {
        switch (el.direction) {
        case Direction::right:
            for (int j = el.coords[1]; j != el.end; ++j) {
                board[el.coords[0]][j] = 0;
            }
            break;
        case Direction::down:
            for (int i = el.coords[0]; i != el.end; ++i) {
                board[i][el.coords[1]] = 0;
            }
            break;
        default:
            assert(false && "unknown direction");
        }
    }
}

void drop(std::vector<std::vector<int>>& board) {
    for (int j = 0; j - board[0].size(); ++j) {
        int first_nonnull = board.size();
        while (first_nonnull - 1 >= 0 && board[first_nonnull - 1][j] != 0) {
            --first_nonnull;
        }
        if (first_nonnull == 0) {
            continue;
        }
        int last_null = first_nonnull - 1;
        for (int i = last_null - 1; i != -1; --i) {
            if (board[i][j] != 0) {
                board[last_null][j] = board[i][j];
                board[i][j] = 0;
                --last_null;
            }
        }
    }
}

using std::vector;

class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        vector<Elimination> eliminations = getEliminations(board);
        while (!eliminations.empty()) {
            eliminate(board, eliminations);
            drop(board);
            eliminations = getEliminations(board);
        }
        return board;
    }
};


#ifndef TEST
int main() {
    return 0;
}
#endif

///////////////////////////////////////////////////////////////////////////////

#include <cassert>  // assert
#include <iostream>  // std::cout std::cerr std::endl

static void print_board(const std::vector<std::vector<int>>& board,
                        std::ostream& out) {
    for (auto& row : board) {
        for (int x : row) {
            out << x << "\t";
        }
        out << std::endl;
    }
}

static bool test_board(std::vector<std::vector<int>> board,
                       std::vector<std::vector<int>> expected) {
    std::vector<std::vector<int>> input = board;
    std::vector<std::vector<int>> result = Solution().candyCrush(board);
    if (result.size() != expected.size() || result[0].size() != expected[0].size()) {
        std::cerr << "board size does not expected size: (" 
                  << result.size() << "," << result[0].size() << ") != ("
                  << expected.size() << "," << expected[0].size() << ")"
                  << std::endl;
        return false;
    }
    for (int i = 0; i - expected.size(); ++i) {
        for (int j = 0; j - expected[0].size(); ++j) {
            if (result[i][j] != expected[i][j]) {
                std::cerr << "result board and expected boards are not equal:\n"
                          << "input board:" << std::endl;
                print_board(input, std::cerr);
                std::cerr << "result board:" << std::endl;
                print_board(result, std::cerr);
                std::cerr << "expected board:" << std::endl;
                print_board(expected, std::cerr);
                return false;
            }
        }
    }
    return true;
}

static void test() {
    assert(test_board({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}},
                      {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}));
    assert(test_board({{0, 0, 0}, {0, 0, 0}, {1, 1, 1}},
                      {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}));
    assert(test_board({{0, 0, 1}, {0, 0, 1}, {1, 1, 1}},
                      {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}));
    assert(test_board({{0, 0, 1}, {0, 0, 1}, {1, 1, 2}},
                      {{0, 0, 1}, {0, 0, 1}, {1, 1, 2}}));
    assert(test_board({{0, 0, 1}, {1, 1, 1}, {1, 2, 1}},
                      {{0, 0, 0}, {0, 0, 0}, {1, 2, 0}}));
    assert(test_board({{0, 0, 0}, {1, 0, 0}, {1, 1, 1}},
                      {{0, 0, 0}, {0, 0, 0}, {1, 0, 0}}));
    assert(test_board({{110,5,112,113,114},
                       {210,211,5,213,214},
                       {310,311,3,313,314},
                       {410,411,412,5,414},
                       {5,1,512,3,3},
                       {610,4,1,613,614},
                       {710,1,2,713,714},
                       {810,1,2,1,1},
                       {1,1,2,2,2},
                       {4,1,4,4,1014}},
                      {{0,0,0,0,0},
                       {0,0,0,0,0},
                       {0,0,0,0,0},
                       {110,0,0,0,114},
                       {210,0,0,0,214},
                       {310,0,0,113,314},
                       {410,0,0,213,414},
                       {610,211,112,313,614},
                       {710,311,412,613,714},
                       {810,411,512,713,1014}}));
    assert(test_board({{1,3,5,5,2},
                       {3,4,3,3,1},
                       {3,2,4,5,2},
                       {2,4,4,5,5},
                       {1,4,4,1,1}},
                      {{1,3,0,0,0},
                       {3,4,0,5,2},
                       {3,2,0,3,1},
                       {2,4,0,5,2},
                       {1,4,3,1,1}}));
    std::cout << "ALL TESTS PASSED" << std::endl;
}

#ifdef TEST
int main() {
    test();
    return 0;
}
#endif
