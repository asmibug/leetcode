#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define ASSERT_VECT(expected, result) do { \
    const auto& _expected = expected; \
    const auto& _result = result; \
    ASSERT_EQ(_expected.size(), _result.size()); \
    for (size_t i = 0; i < _expected.size(); ++i) { \
        EXPECT_EQ(_expected[i], _result[i]); \
    } \
} while (0) \

UTEST(GetNumSortEnds, 1) {
    ASSERT_VECT((std::vector<int>{1,2,2,2}),
                (GetNumSortEnds({{1,6},{3,7},{9,12},{4,13}},
                                        {2,3,7,11})));
}

UTEST(GetNumSortEnds, 2) {
    ASSERT_VECT((std::vector{2,2,1}),
                (GetNumSortEnds({{1,10},{3,3}}, {3,3,2})));
}


UTEST(GetNumHeap, 1) {
    ASSERT_VECT((std::vector<int>{1,2,2,2}),
                (GetNumHeap({{1,6},{3,7},{9,12},{4,13}},
                                        {2,3,7,11})));
}

UTEST(GetNumHeap, 2) {
    ASSERT_VECT((std::vector{2,2,1}),
                (GetNumHeap({{1,10},{3,3}}, {3,3,2})));
}


UTEST(GetNumTwoPointers, 1) {
    ASSERT_VECT((std::vector<int>{1,2,2,2}),
                (GetNumTwoPointers({{1,6},{3,7},{9,12},{4,13}},
                                        {2,3,7,11})));
}

UTEST(GetNumTwoPointers, 2) {
    ASSERT_VECT((std::vector{2,2,1}),
                (GetNumTwoPointers({{1,10},{3,3}}, {3,3,2})));
}
