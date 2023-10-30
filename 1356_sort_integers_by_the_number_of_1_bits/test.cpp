#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define ASSERT_VECT(expected, result) do { \
    auto _expected = expected; \
    auto _result = result; \
    ASSERT_EQ(_expected.size(), _result.size()); \
    for (unsigned i = 0; i < _expected.size(); ++i) { \
        EXPECT_EQ(_expected[i], _result[i]); \
    } \
} while (0) \

UTEST(SortByBits, 1) {
    ASSERT_VECT(std::vector({0,1,2,4,8,3,5,6,7}),
                SortByBits({0,1,2,3,4,5,6,7,8}));
}

UTEST(SortByBits, 2) {
    ASSERT_VECT(std::vector({1,2,4,8,16,32,64,128,256,512,1024}),
                SortByBits({1024,512,256,128,64,32,16,8,4,2,1}));
}
