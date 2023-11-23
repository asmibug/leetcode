#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define ASSERT_VECT(expected, result) do { \
    auto _expected = expected; \
    auto _result = result; \
    ASSERT_EQ(_expected.size(), _result.size()); \
    for (auto i = 0u; i < _expected.size(); ++i) { \
        EXPECT_EQ(_expected[i], _result[i]); \
    } \
} while (0) \

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    ASSERT_VECT((std::vector{1,4,2,7,5,3,8,6,9}), \
                func({{1,2,3}, \
                      {4,5,6}, \
                      {7,8,9}})); \
} \
UTEST(func, 2) { \
    ASSERT_VECT((std::vector{1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16}), \
                func({{1,2,3,4,5}, \
                      {6,7}, \
                      {8}, \
                      {9,10,11}, \
                      {12,13,14,15,16}})); \
} \
UTEST(func, 3) { \
    ASSERT_VECT((std::vector{1,2,3,4,5,6}), \
                func({{1,2,3,4,5,6}})); \
} \
UTEST(func, 4) { \
    ASSERT_VECT((std::vector{14,13,12,11,14,19,13,15,16,1,8,9,11}), \
                func({{14,12,19,16,9},{13,14,15,8,11},{11,13,1}})); \
} \

INSERT_TESTS(GetDiagonalOrderTraverse)
INSERT_TESTS(GetDiagonalOrderSort)
INSERT_TESTS(GetDiagonalOrderVect)
INSERT_TESTS(GetDiagonalOrderBfs)
INSERT_TESTS(GetDiagonalOrderBfsInplace)
