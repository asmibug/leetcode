#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define ASSERT_VECT(expected, result) do { \
    auto _expected = expected; \
    auto _result = result; \
    ASSERT_EQ(_expected.size(), _result.size()); \
    for (auto i = 0u; i < _expected.size(); ++i) { \
        EXPECT_EQ(_expected[i] + 0, _result[i] + 0); \
    } \
} while (0) \

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    ASSERT_VECT((std::vector<bool>{true,false,true}), \
                func({4,6,5,9,3,7}, {0,0,2}, {2,3,5})); \
} \
UTEST(func, 2) { \
    ASSERT_VECT((std::vector<bool>{false,true,false,false,true,true}), \
                func({-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10}, \
                     {0,1,6,4,8,7}, {4,4,9,7,9,10})); \
} \

INSERT_TESTS(CheckArithmeticSubarraysBySort)
INSERT_TESTS(CheckArithmeticSubarraysByVect)
INSERT_TESTS(CheckArithmeticSubarraysByPresort)
