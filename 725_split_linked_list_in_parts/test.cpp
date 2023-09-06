#include "lib.cpp"

#include "utest.h"


namespace {  // auxiliary
    std::vector<ListNode> CreateList(const std::vector<int>& values) {
        std::vector<ListNode> list;
        list.reserve(values.size());
        for (int value : values) {
            list.emplace_back(value);
        }
        for (unsigned i = 1; i < list.size(); ++i) {
            list[i - 1].next = &list[i];
        }
        return list;
    }
}

UTEST(Utest, TestUtestWorking) {
    EXPECT_TRUE(true);
}

UTEST(CreateList, Zero) {
    std::vector<ListNode> list = CreateList(std::vector<int>{});
    EXPECT_EQ(0u, list.size());
}

UTEST(CreateList, One) {
    auto list = CreateList({1});
    EXPECT_EQ(1u, list.size());
    EXPECT_EQ(1, list[0].val);
    EXPECT_TRUE(nullptr == list[0].next);
}

UTEST(CreateList, Two) {
    auto list = CreateList({1, 2});
    EXPECT_EQ(2u, list.size());
    EXPECT_EQ(1, list[0].val);
    EXPECT_EQ(2, list[1].val);
    EXPECT_EQ(&list[1], list[0].next);
    EXPECT_TRUE(nullptr == list[1].next);
}

UTEST(GetListLen, Zero) {
    EXPECT_EQ(0u, GetListLen(nullptr));
}

UTEST(GetListLen, One) {
    auto list = CreateList({1});
    EXPECT_EQ(list.size(), GetListLen(&list[0]));
}

UTEST(GetListLen, Two) {
    auto list = CreateList({1, 2});
    EXPECT_EQ(list.size(), GetListLen(&list[0]));
}

UTEST(SplitList, ZeroToOne) {
    std::vector<ListNode*> result = SplitList(nullptr, 1);
    ASSERT_EQ(1u, result.size());
    EXPECT_TRUE(nullptr == result[0]);
}

UTEST(SplitList, ZeroToTwo) {
    auto result = SplitList(nullptr, 2);
    ASSERT_EQ(2u, result.size());
    EXPECT_TRUE(nullptr == result[0]);
    EXPECT_TRUE(nullptr == result[1]);
}

UTEST(SplitList, OneToOne) {
    auto list = CreateList({1});
    auto result = SplitList(&list[0], 1);
    ASSERT_EQ(1u, result.size());
    EXPECT_EQ(1, result[0]->val);
    EXPECT_TRUE(nullptr == result[0]->next);
}

UTEST(SplitList, OneToTwo) {
    auto list = CreateList({1});
    auto result = SplitList(&list[0], 2);
    ASSERT_EQ(2u, result.size());
    EXPECT_EQ(1, result[0]->val);
    EXPECT_TRUE(nullptr == result[0]->next);
    EXPECT_TRUE(nullptr == result[1]);
}

UTEST(SplitList, TwoToTwo) {
    auto list = CreateList({1, 2});
    auto result = SplitList(&list[0], 2);
    ASSERT_EQ(2u, result.size());
    EXPECT_EQ(1, result[0]->val);
    EXPECT_TRUE(nullptr == result[0]->next);
    EXPECT_EQ(2, result[1]->val);
    EXPECT_TRUE(nullptr == result[1]->next);
}

UTEST_MAIN();
