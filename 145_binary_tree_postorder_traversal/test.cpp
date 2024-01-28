#include "lib.cpp"

#include "utest.h"

UTEST_MAIN()

#define INSERT_TESTS(func) \
UTEST(func, 1) { \
    std::vector<TreeNode> tree; \
    tree.reserve(3); \
    tree.emplace_back(3); \
    tree.emplace_back(2, &tree.back(), nullptr); \
    tree.emplace_back(1, nullptr, &tree.back()); \
    auto result = func(&tree.back()); \
    ASSERT_EQ(3u, result.size()); \
    EXPECT_EQ(3, result[0]); \
    EXPECT_EQ(2, result[1]); \
    EXPECT_EQ(1, result[2]); \
 \
    EXPECT_EQ(0u, func(nullptr).size()); \
 \
    result = func(&tree.front()); \
    ASSERT_EQ(1u, result.size()); \
    EXPECT_EQ(3, result[0]); \
} \

INSERT_TESTS(PostorderRecursive)
INSERT_TESTS(PostorderIterativeByReversePreorder)
INSERT_TESTS(PostorderIterativeByStateStore)
INSERT_TESTS(PostorderIterativeByState)
INSERT_TESTS(PostorderIterativeBySeen)
INSERT_TESTS(PostorderIterativeByHashset)
INSERT_TESTS(PostorderIterativeByDouble)
INSERT_TESTS(PostorderIterativeByLastProcessed)
INSERT_TESTS(PostorderIterativeByMoveDown)
INSERT_TESTS(PostorderIterativeByMorris)
INSERT_TESTS(PostorderIterativeByMorrisDummy)

INSERT_TESTS(PostorderIterativeByCycle)
INSERT_TESTS(PostorderIterativeByFlag)
INSERT_TESTS(PostorderIterativeByPrev)
