#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

bool IsValid(const std::vector<int>& nums) {
    bool seen_odd = false;
    for (int x : nums) {
        if (x % 2 != 0) {
            seen_odd = true;
        } else if (seen_odd) {
            return false;
        }
    }
    return true;
}

UTEST(SortByParity, 1) {
    EXPECT_TRUE(IsValid(SortByParity({3, 1, 2, 4})));
}

UTEST(SortByParity, 2) {
    EXPECT_TRUE(IsValid(SortByParity({0})));
}
