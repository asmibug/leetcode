#include "lib.cpp"  // ListNode

#include <vector>  // std::vector

#include "utest.h"

namespace {  // auxiliary
    std::vector<ListNode> CreateList(const std::vector<int>& values) {
        std::vector<ListNode> list;
        list.reserve(values.size());
        for (int v : values) {
            list.emplace_back(v);
        }
        for (unsigned i = 1; i < values.size(); ++i) {
            list[i - 1].next = &list[i];
        }
        return list;
    }
}

UTEST(Utest, TestUtest) {
    EXPECT_TRUE(true);
}

UTEST(CreateList, Empty) {
    std::vector<ListNode> list = CreateList(std::vector<int>{});
    EXPECT_EQ(0u, list.size());
}

UTEST(CreateList, Two) {
    std::vector<int> values = {1, 2, 3};
    auto list = CreateList(values);
    ASSERT_EQ(values.size(), list.size());
    for (unsigned i = 0; i < values.size(); ++i) {
        EXPECT_EQ(values[i], list[i].val);
    }
    EXPECT_EQ(list[0].next, &list[1]);
    EXPECT_EQ(list[1].next, &list[2]);
    EXPECT_TRUE(nullptr == list[2].next);
}

#define INSERT_TESTS_FOR(function) \
    UTEST(function, OneElement) { \
        auto list = CreateList({1}); \
        ListNode* result = function(&list[0], 1, 1); \
        EXPECT_EQ(&list[0], result); \
        EXPECT_EQ(1, result->val); \
        EXPECT_TRUE(nullptr == result->next); \
    } \
 \
    UTEST(function, TwoElementsReverse2) { \
        auto list = CreateList({1, 2}); \
        auto result = function(&list[0], 1, 2); \
        EXPECT_EQ(&list[1], result); \
        EXPECT_EQ(&list[0], result->next); \
        EXPECT_TRUE(nullptr == result->next->next); \
        EXPECT_EQ(2, result->val); \
        EXPECT_EQ(1, result->next->val); \
    } \
 \
    UTEST(function, ThreeElementsReverseOneMiddle) { \
        auto list = CreateList({1, 2, 3}); \
        auto result = function(&list[0], 2, 2); \
        EXPECT_EQ(&list[0], result); \
        EXPECT_EQ(&list[1], result->next); \
        EXPECT_EQ(&list[2], result->next->next); \
        EXPECT_TRUE(nullptr == result->next->next->next); \
        EXPECT_EQ(1, result->val); \
        EXPECT_EQ(2, result->next->val); \
        EXPECT_EQ(3, result->next->next->val); \
    } \
 \
    UTEST(function, FourElementsReverseTwoMiddle) { \
        auto list = CreateList({1, 2, 3, 4}); \
        auto result = function(&list[0], 2, 3); \
        EXPECT_EQ(&list[0], result); \
        EXPECT_EQ(&list[2], result->next); \
        EXPECT_EQ(&list[1], result->next->next); \
        EXPECT_EQ(&list[3], result->next->next->next); \
        EXPECT_TRUE(nullptr == result->next->next->next->next); \
        EXPECT_EQ(1, result->val); \
        EXPECT_EQ(3, result->next->val); \
        EXPECT_EQ(2, result->next->next->val); \
        EXPECT_EQ(4, result->next->next->next->val); \
    }

INSERT_TESTS_FOR(ReverseBetweenRecursion)

INSERT_TESTS_FOR(ReverseBetweenIteration)

UTEST_MAIN();
