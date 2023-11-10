#include <algorithm>

#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define ASSERT_VECT(expected, result) do { \
    const auto& _expected = expected; \
    auto _result = result; \
    ASSERT_EQ(_expected.size(), _result.size()); \
    if (_expected[0] != _result[0]) { \
        std::ranges::reverse(_result); \
    } \
    for (auto i = 0u; i < _expected.size(); ++i) { \
        EXPECT_EQ(_expected[i], _result[i]); \
    } \
} while (0) \

UTEST(RestoreArrayHash, 1) {
    ASSERT_VECT((std::vector{1,2,3,4}), RestoreArrayHash({{2,1},{3,4},{3,2}}));    
}

UTEST(RestoreArrayHash, 2) {
    ASSERT_VECT((std::vector{-2,4,1,-3}), RestoreArrayHash({{4,-2},{1,4},{-3,1}}));
}

UTEST(RestoreArrayHash, 3) {
    ASSERT_VECT((std::vector{100000,-100000}),
                RestoreArrayHash({{100000,-100000}}));
}
