#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(ReverseXor, 1) {
    std::vector<int> expected = {5,7,2,3,2};
    std::vector<int> result = ReverseXor({5,2,0,3,1});
    ASSERT_EQ(expected.size(), result.size());
    for (unsigned i = 0; i < expected.size(); ++i) {
        EXPECT_EQ(expected[i], result[i]);
    }
}


UTEST(ReverseXor, 2) {
    auto result = ReverseXor({13});
    ASSERT_EQ(1u, result.size());
    EXPECT_EQ(13, result[0]);
}
