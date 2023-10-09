#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define ASSERT_VECTOR(expected, result) do { \
    const auto& _expected = expected; \
    const auto& _result = result; \
    ASSERT_EQ(_expected.size(), _result.size()); \
    for (auto i = 0ull; i < _expected.size(); ++i) { \
        EXPECT_EQ(_expected[i], _result[i]); \
    } \
} while (0) \

UTEST(GetBounds, 1) {
    ASSERT_VECTOR((std::vector<int>{3,4}), (GetBounds({5,7,7,8,8,10}, 8)));
}

UTEST(GetBounds, 2) {
    ASSERT_VECTOR((std::vector<int>{-1,-1}), (GetBounds({5,7,7,8,8,10}, 6)));
}

UTEST(GetBounds, 3) {
    ASSERT_VECTOR((std::vector<int>{-1,-1}), (GetBounds({}, 0)));
}
