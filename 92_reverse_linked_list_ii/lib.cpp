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

ListNode* ReverseBetweenIteration(ListNode* head, int left, int right) {
    ListNode dummy(0, head);
    ListNode* cur = &dummy;
    for (int i = 1; i < left; ++i) {
        cur = cur->next;
    }
    auto left_end = cur;
    auto next = cur->next;
    for (int i = 0; i < right - left + 1; ++i) {
        auto prev = cur;
        cur = next;
        next = cur->next;
        cur->next = prev;
    }
    left_end->next->next = next;
    left_end->next = cur;
    return dummy.next;
}

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        return ReverseBetweenIteration(head, left, right);
    }
};
