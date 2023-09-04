#include <vector>  // std::vector
#include <unordered_set>  // std::unordered_set

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool HasCycleSet(const ListNode* head) {
    std::unordered_set<const ListNode *> seen;
    for (; head != nullptr; head = head->next) {
        if (seen.count(head)) {
            return true;
        }
        seen.insert(head);
    }
    return false;
}

bool HasCycle2Pointers(const ListNode* head) {
    if (head == nullptr) {
        return false;
    }
    const ListNode* slow = head;
    const ListNode* fast = head->next;
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
        if (fast != nullptr) {
            fast = fast->next;
        }
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

class Solution {
public:
    bool hasCycle(ListNode* head) {
        return HasCycle2Pointers(head);
    }
};

std::vector<ListNode> ConstructList(const std::vector<int>& elements, int pos) {
    std::vector<ListNode> list;
    for (int el : elements) {
        list.emplace_back(el);
    }
    for (unsigned i = 0; i + 1 < list.size(); ++i) {
        list[i].next = &list[i + 1];
    }
    if (pos == -1) {
        list.back().next = nullptr;
    } else {
        list.back().next = &list[pos];
    }
    return list;
}

///////////////////////////////////////////////////////////////////////////////

#include "acutest.h"  // TEST_ASSERT TEST_CHECK TEST_LIST TEST_MSG

void TestAcutest() {
    TEST_CHECK(true);
    TEST_MSG("true check should be ok");
}

void TestConstructList() {
    std::vector<int> values = {0, 1, 2};
    auto list = ConstructList(values, -1);
    TEST_CHECK(list.back().next == nullptr);
    ListNode* head = &list.front();
    for (int v : values) {
        TEST_ASSERT(head != nullptr);
        TEST_CHECK(head->val == v);
        TEST_MSG("head->val = %d, v = %d", head->val, v);
        head = head->next;
    }
    TEST_CHECK(head == nullptr);
    TEST_MSG("head: %p", static_cast<void*>(head));
}

void TestConstructListWithCycle() {
    auto list = ConstructList({0, 1, 2}, 0);
    TEST_CHECK(list.back().next == &list.front());
}

void TestHasCycleNoCycle(bool (*function)(const ListNode*)) {
    auto list = ConstructList({1}, -1);
    TEST_CHECK(function(&list.front()) == false);
}

void TestHasCycleWithCycle(bool (*function)(const ListNode*)) {
    auto list = ConstructList({1, 2}, 0);
    TEST_CHECK(function(&list.front()) == true);
}

void TestHasCycleWithShortCycle(bool (*function)(const ListNode*)) {
    auto list = ConstructList({3, 2, 0, -4}, 1);
    TEST_CHECK(function(&list.front()) == true);
}

void TestHasCycleSetNoCycle() {
    TestHasCycleNoCycle(&HasCycleSet);
}

void TestHasCycleSetWithCycle() {
    TestHasCycleWithCycle(&HasCycleSet);
}

void TestHasCycleSetWithShortCycle() {
    TestHasCycleWithShortCycle(&HasCycleSet);
}

void TestHasCycle2PointersNoCycle() {
    TestHasCycleNoCycle(&HasCycle2Pointers);
}

void TestHasCycle2PointersWithCycle() {
    TestHasCycleWithCycle(&HasCycle2Pointers);
}

void TestHasCycle2PointersWithShortCycle() {
    TestHasCycleWithShortCycle(&HasCycle2Pointers);
}

TEST_LIST = {
    {"check acutest is working", TestAcutest},
    {"test ConstructList", TestConstructList},
    {"test ConstructList with cycle", TestConstructListWithCycle},
    {"test HasCycleSet with no cycle", TestHasCycleSetNoCycle},
    {"test HasCycleSet with cycle", TestHasCycleSetWithCycle},
    {"test HasCycleSet with short cycle", TestHasCycleSetWithShortCycle},
    {"test HasCycle2Pointers with no cycle", TestHasCycle2PointersNoCycle},
    {"test HasCycle2Pointers with cycle", TestHasCycle2PointersWithCycle},
    {"test HasCycle2Pointers with short cycle", TestHasCycle2PointersWithShortCycle},
    {NULL, NULL}
};
