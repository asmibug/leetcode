/**
 * https://leetcode.com/problems/reverse-linked-list-ii/
 * 
 * The task should be solved iteratively.
 * The dummy node should be used to simplify the code.
 * There are 2 approaches:
 * 1) Reverse the connections of individual nodes, and then reconnect the list
 * 2) Iteratively move nodes to the beginning
*/

/**/
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
/**/

void ReverseListRecursive(ListNode* head, int len,
                          ListNode** result_first, ListNode** result_last) {
    if (len <= 1) {
        *result_first = head;
        *result_last = head;
        return;
    }
    ListNode* first;
    ListNode* last;
    ReverseListRecursive(head->next, len - 1, &first, &last);
    auto tail = last->next;
    last->next = head;
    head->next = tail;
    *result_first = first;
    *result_last = head;
}

ListNode* ReverseBetweenRecursion(ListNode* head, int left, int right) {
    ListNode dummy(0, head);

    auto left_end = &dummy;
    for (int i = 1; i < left; ++i) {
        left_end = left_end->next;
    }
    ListNode* first;
    ListNode* last;
    ReverseListRecursive(left_end->next, right - left + 1,
                         &first, &last);
    left_end->next = first;
    return dummy.next;
}

ListNode* ReverseBetweenIteration1(ListNode* head, int left, int right) {
    ListNode dummy(0, head);
    ListNode* cur = &dummy;
    for (int i = 1; i < left; ++i) {
        cur = cur->next;
    }
    auto left_end = cur;
    auto next = cur->next;
    for (int i = left; i <= right; ++i) {
        auto prev = cur;
        cur = next;
        next = cur->next;
        cur->next = prev;
    }
    left_end->next->next = next;
    left_end->next = cur;
    return dummy.next;
}

ListNode* ReverseBetweenIteration2(ListNode* head, int left, int right) {
    ListNode dummy(0, head);
    ListNode* cur = &dummy;
    for (int i = 1; i < left; ++i) {
        cur = cur->next;
    }
    auto left_end = cur;
    auto tail = cur->next;
    for (int i = left + 1; i <= right; ++i) {
        auto node = tail->next;
        tail->next = node->next;
        node->next = left_end->next;
        left_end->next = node;
    }
    return dummy.next;
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        return ReverseBetweenIteration1(head, left, right);
    }
};
