#include "lib.cpp"

#include "utest.h"

UTEST(Utest, CanaryTest) {
    EXPECT_TRUE(true);
}

UTEST(GetPascalTriangle, One) {
    std::vector<std::vector<int>> result = GetPascalTriangle(1);
    ASSERT_EQ(1u, result.size());
    EXPECT_EQ(1, result[0][0]);
}

#define INSERT_TEST(num_rows, ...) \
UTEST(GetPascalTriangle, NumElements ## num_rows) { \
    auto result = GetPascalTriangle(num_rows); \
    decltype(result) expected = __VA_ARGS__; \
    ASSERT_EQ(expected.size(), result.size()); \
    for (unsigned i = 0; i < expected.size(); ++i) { \
        ASSERT_EQ(expected[i].size(), result[i].size()); \
    } \
    for (unsigned i = 0; i < expected.size(); ++i) { \
        for (unsigned j = 0; j < expected[i].size(); ++j) { \
            EXPECT_EQ(expected[i][j], result[i][j]); \
        } \
    } \
}

INSERT_TEST(2, {{1}, {1, 1}})

INSERT_TEST(3, {{1}, {1, 1}, {1, 2, 1}})

INSERT_TEST(4, {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}})

UTEST_MAIN();
