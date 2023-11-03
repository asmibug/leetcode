#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define ASSERT_STRVECT(expected, result) do { \
    auto _expected = expected; \
    auto _result = result; \
    ASSERT_EQ(_expected.size(), _result.size()); \
    for (auto i = 0u; i < _expected.size(); ++i) { \
        EXPECT_STREQ(_expected[i].c_str(), _result[i].c_str()); \
    } \
} while (0) \

UTEST(BuildArray, 1) {
    ASSERT_STRVECT((std::vector<std::string>{"Push","Push","Pop","Push"}),
                   BuildArray({1,3}, 3));
}

UTEST(BuildArray, 2) {
    ASSERT_STRVECT((std::vector<std::string>{"Push","Push","Push"}),
                   BuildArray({1,2,3}, 3));
}

UTEST(BuildArray, 3) {
    ASSERT_STRVECT((std::vector<std::string>{"Push","Push"}),
                   BuildArray({1,2}, 4));
}
