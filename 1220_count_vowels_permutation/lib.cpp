static constexpr int kMod = 1e9 + 7;
static constexpr int sz = 5;

struct Matrix {
    int data[sz][sz];
};

Matrix Mult(const Matrix& x, const Matrix& y) {
    Matrix res = {0};
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            for (int k = 0; k < sz; ++k) {
                res.data[i][j] = (
                    res.data[i][j] + 1LL * x.data[i][k] * y.data[k][j]) % kMod;
            }
        }
    }
    return res;
}

Matrix Pow(Matrix matrix, int n) {
    Matrix res = {0};
    for (int i = 0; i < sz; ++i) {
        res.data[i][i] = 1;
    }
    for (; n; n >>= 1) {
        if (n & 1) {
            res = Mult(res, matrix);
        }
        matrix = Mult(matrix, matrix);
    }
    return res;
}

int CountVowelPermutation(int n) {
    Matrix matrix = {0, 1, 1, 0, 1,
                     1, 0, 1, 0, 0,
                     0, 1, 0, 1, 0,
                     0, 0, 1, 0, 0,
                     0, 0, 1, 1, 0};
    matrix = Pow(matrix, n - 1);
    auto res = 0LL;
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            res += matrix.data[i][j];
        }
    }
    return res % kMod;
}

class Solution {
public:
    int countVowelPermutation(int n) {
        return CountVowelPermutation(n);
    }
};
