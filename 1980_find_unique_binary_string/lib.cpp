#include <string>
#include <vector>

int Str2Num(const std::string& s) {
    int num = 0;
    int base = 1;
    for (char c : s) {
        if (c == '1') {
            num += base;
        }
        base <<= 1;
    }
    return num;
}

std::string Num2Str(int n) {
    std::string s;
    for (; n; n >>= 1) {
        if (n & 1) {
            s.push_back('1');
        } else {
            s.push_back('0');
        }
    }
    return s;
}

std::string GetDifferentParse(const std::vector<std::string>& nums) {
    std::vector<bool> seen(1 << 16, false);
    for (const auto& s : nums) {
        seen[Str2Num(s)] = true;
    }
    int i = 0;
    while (seen[i]) {
        ++i;
    }
    std::string res = Num2Str(i);
    res.resize(nums[0].size(), '0');
    return res;
}

std::string GetDifferentDiagonal(const std::vector<std::string>& nums) {
    int n = nums.size();
    std::string res;
    res.reserve(n);
    for (int i = 0; i < n; ++i) {
        res.push_back(((nums[i][i] - '0') ^ 1) + '0');
    }
    return res;
}

using std::string;
using std::vector;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        return GetDifferentDiagonal(nums);
    }
};
