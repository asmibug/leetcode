#include <unordered_set>

#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

bool CheckRes(const std::vector<std::string>& nums, const std::string& res) {
    if (res.size() != nums.size()) {
        return false;
    }
    for (char c : res) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    std::unordered_set set(nums.begin(), nums.end());
    return !set.contains(res);
}

#define CHECK(func, input, name) \
UTEST(func, name) { \
    std::vector<std::string> _input = input; \
    std::string result = func(input); \
    EXPECT_TRUE_MSG(CheckRes(input, result), result.c_str()); \
} \

#define INSERT_TESTS(func) \
CHECK(func, std::vector<std::string>({"01","10"}), 1) \
CHECK(func, std::vector<std::string>({"00","01"}), 2) \
CHECK(func, std::vector<std::string>({"111","011","001"}), 3) \

INSERT_TESTS(GetDifferentParse)
INSERT_TESTS(GetDifferentDiagonal)
