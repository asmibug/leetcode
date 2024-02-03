#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

UTEST(GeneratePossibleMoves, 1) {
    std::vector<std::string> res = GeneratePossibleMoves("++++");
    ASSERT_EQ(3u, res.size());
    EXPECT_STREQ("--++", res[0].c_str());
    EXPECT_STREQ("+--+", res[1].c_str());
    EXPECT_STREQ("++--", res[2].c_str());

    EXPECT_EQ(0u, GeneratePossibleMoves("+").size());
}
