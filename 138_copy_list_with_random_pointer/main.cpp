#include <vector>  // std::vector
#include <unordered_map>  // std::unordered_map


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


struct NodeInfo {
    int val;
    int link;
};

std::vector<NodeInfo> ListToListInfo(const Node* head) {
    std::vector<NodeInfo> list_info;
    if (head == nullptr) {
        return list_info;
    }
    std::unordered_map<const Node*, int> node_idx;
    for (int i = 0; head; head = head->next, ++i) {
        node_idx[head] = i;
        list_info.push_back(NodeInfo{head->val, -1});
    }
    for (auto& [node, idx] : node_idx) {
        if (node->random) {
            list_info[idx].link = node_idx[node->random];
        }
    }
    return list_info;
}

Node* ConstructList(const std::vector<NodeInfo>& list_info) {
    Node* head = nullptr;
    std::vector<Node*> nodes(list_info.size());
    for (int i = list_info.size() - 1; i != -1; --i) {
        auto new_head = new Node(list_info[i].val);
        nodes[i] = new_head;
        new_head->next = head;
        head = new_head;
    }
    for (unsigned i = 0; i < list_info.size(); ++i) {
        if (list_info[i].link != -1) {
            nodes[i]->random = nodes[list_info[i].link];
        }
    }
    return head;
}

Node* CopyListIterative(const Node* head) {
    if (!head) {
        return nullptr;
    }
    std::unordered_map<const Node*, Node*> old_to_new;
    auto head_copy = new Node(head->val);
    old_to_new[head] = head_copy;
    if (head->random && !old_to_new.count(head->random)) {
        auto random_copy = new Node(head->random->val);
        old_to_new[head->random] = random_copy;
    }
    head_copy->random = old_to_new[head->random];
    auto cur_copy = head_copy;
    for (auto next = head->next; next; next = next->next) {
        if (!old_to_new.count(next)) {
            auto next_copy = new Node(next->val);
            old_to_new[next] = next_copy;
        }
        auto next_copy = old_to_new[next];
        cur_copy->next = next_copy;
        cur_copy = next_copy;
        if (next->random && !old_to_new.count(next->random)) {
            auto random_copy = new Node(next->random->val);
            old_to_new[next->random] = random_copy;
        }
        cur_copy->random = old_to_new[next->random];
    }
    return head_copy;
}

Node* CopyListLowMem(Node* head) {
    if (!head) {
        return nullptr;
    }
    for (auto cur = head; cur;) {
        auto cur_copy = new Node(cur->val);
        cur_copy->next = cur->next;
        cur->next = cur_copy;
        cur = cur_copy->next;
    }
    auto copy = head->next;
    for (auto cur = head; cur;) {
        auto cur_copy = cur->next;
        if (auto cur_random = cur->random) {
            auto cur_random_copy = cur_random->next;
            cur_copy->random = cur_random_copy;
        }
        cur = cur_copy->next;
    }
    for (auto cur = head; cur;) {
        auto cur_copy = cur->next;
        auto next_cur = cur_copy->next;
        cur->next = next_cur;
        if (next_cur) {
            cur_copy->next = next_cur->next;
        }
        cur = next_cur;
    }
    return copy;
}

void DestroyList(Node* head) {
    while (head) {
        auto new_head = head->next;
        delete head;
        head = new_head;
    }
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        auto list_info = ListToListInfo(head);
        return ConstructList(list_info);
    }
};

///////////////////////////////////////////////////////////////////////////////

std::vector<Node> ConstructListInVector(const std::vector<NodeInfo>& list_info) {
    std::vector<Node> list;
    list.reserve(list_info.size());
    if (list_info.empty()) {
        return list;
    }
    list.emplace_back(list_info[0].val);
    for (unsigned i = 1; i < list_info.size(); ++i) {
        list.emplace_back(list_info[i].val);
        list[i - 1].next = &list[i];
    }
    list.back().next = nullptr;
    for (unsigned i = 0; i < list_info.size(); ++i) {
        if (list_info[i].link == -1) {
            list[i].random = nullptr;
        } else {
            list[i].random = &list[list_info[i].link];
        }
    }
    return list;
}

#ifndef TEST
int main() {
    return 0;
}
#endif

///////////////////////////////////////////////////////////////////////////////

#include "utest.h"  // EXPECT_EQ EXPECT_TRUE UTEST UTEST_MAIN UTEST_STATE

UTEST(Utest, TestWorking) {
    EXPECT_TRUE(true);
}

namespace {  // fixtures
    std::vector<NodeInfo> GetListInfoOneToNull() {
        return {{1, -1}};
    }

    std::vector<NodeInfo> GetListInfoOneToSelf() {
        return {{0, 0}};
    }

    std::vector<NodeInfo> GetListInfoThree() {
        return {{0, 2}, {1, -1}, {2, 0}};
    }
}

UTEST(ConstructListInVector, Zero) {
    auto list = ConstructListInVector({});
    EXPECT_EQ(0u, list.size());
}

UTEST(ConstructListInVector, OneToNull) {
    auto list = ConstructListInVector(GetListInfoOneToNull());
    EXPECT_EQ(1u, list.size());
    EXPECT_EQ(1, list[0].val);
    EXPECT_TRUE(nullptr == list[0].next);
    EXPECT_TRUE(nullptr == list[0].random);
}

UTEST(ConstructListInVector, OneToSelf) {
    auto list = ConstructListInVector(GetListInfoOneToSelf());
    EXPECT_EQ(&list[0], list[0].random);
}

UTEST(ConstructListInVector, Three) {
    auto list = ConstructListInVector(GetListInfoThree());
    EXPECT_EQ(3u, list.size());
    EXPECT_EQ(0, list[0].val);
    EXPECT_EQ(1, list[1].val);
    EXPECT_EQ(2, list[2].val);
    EXPECT_EQ(&list[1], list[0].next);
    EXPECT_EQ(&list[2], list[1].next);
    EXPECT_TRUE(nullptr == list[2].next);
}

UTEST(ListToListInfo, Zero) {
    auto list_info = ListToListInfo(nullptr);
    EXPECT_EQ(0u, list_info.size());
}

// Can't use EXPECT_* in function, so use macro instead
#define EXPECT_LIST_INFO_EQ(a, b) do { \
    ASSERT_EQ(a.size(), b.size()); \
    for (unsigned i = 0; i < a.size(); ++i) { \
        EXPECT_EQ(a[i].val, b[i].val); \
        EXPECT_EQ(a[i].link, b[i].link); \
    } \
} while (0)

#define CHECK_ListToListInfo(function_to_get_list_info) do { \
    auto expected_list_info = function_to_get_list_info(); \
    auto list = ConstructListInVector(expected_list_info); \
    auto result_list_info = ListToListInfo(&list[0]); \
    EXPECT_LIST_INFO_EQ(expected_list_info, result_list_info); \
} while (0)

UTEST(ListToListInfo, OneToNull) {
    CHECK_ListToListInfo(GetListInfoOneToNull);
}

UTEST(ListToListInfo, OneToSelf) {
    CHECK_ListToListInfo(GetListInfoOneToSelf);
}

UTEST(ListToListInfo, Three) {
    CHECK_ListToListInfo(GetListInfoThree);
}

UTEST(ConstructList, Zero) {
    auto list = ConstructList({});
    EXPECT_TRUE(nullptr == list);
    DestroyList(list);
}

#define CHECK_ConstructList(function_to_get_list_info) do { \
    auto expected_list_info = function_to_get_list_info(); \
    auto list = ConstructList(expected_list_info); \
    auto result_list_info = ListToListInfo(list); \
    EXPECT_LIST_INFO_EQ(expected_list_info, result_list_info); \
    DestroyList(list); \
} while (0)

UTEST(ConstructList, OneToNull) {
    CHECK_ConstructList(GetListInfoOneToNull);
}

UTEST(ConstructList, OneToSelf) {
    CHECK_ConstructList(GetListInfoOneToSelf);
}

UTEST(ConstructList, Three) {
    CHECK_ConstructList(GetListInfoThree);
}

UTEST(CopyListIterative, Zero) {
    auto list = CopyListIterative(nullptr);
    EXPECT_TRUE(nullptr == list);
    DestroyList(list);
}

#define CHECK_CopyListIterative(function_to_get_list_info) do { \
    auto expected_list_info = function_to_get_list_info(); \
    auto list = ConstructListInVector(expected_list_info); \
    auto list_copy = CopyListIterative(&list[0]); \
    auto result_list_info = ListToListInfo(list_copy); \
    EXPECT_LIST_INFO_EQ(expected_list_info, result_list_info); \
    DestroyList(list_copy); \
} while (0)

UTEST(CopyListIterative, OneToNull) {
    CHECK_CopyListIterative(GetListInfoOneToNull);
}

UTEST(CopyListIterative, OneToSelf) {
    CHECK_CopyListIterative(GetListInfoOneToSelf);
}

UTEST(CopyListIterative, Three) {
    CHECK_CopyListIterative(GetListInfoThree);
}

UTEST(CopyListLowMem, Zero) {
    auto list = CopyListLowMem(nullptr);
    EXPECT_TRUE(nullptr == list);
    DestroyList(list);
}

#define CHECK_CopyListLowMem(function_to_get_list_info) do { \
    auto expected_list_info = function_to_get_list_info(); \
    auto list = ConstructListInVector(expected_list_info); \
    auto list_copy = CopyListLowMem(&list[0]); \
    auto result_list_info = ListToListInfo(list_copy); \
    EXPECT_LIST_INFO_EQ(expected_list_info, result_list_info); \
    DestroyList(list_copy); \
} while (0)

UTEST(CopyListLowMem, OneToNull) {
    CHECK_CopyListLowMem(GetListInfoOneToNull);
}

UTEST(CopyListLowMem, OneToSelf) {
    CHECK_CopyListLowMem(GetListInfoOneToSelf);
}

UTEST(CopyListLowMem, Three) {
    CHECK_CopyListLowMem(GetListInfoThree);
}

#ifdef TEST
UTEST_MAIN();
#else
UTEST_STATE();
#endif
