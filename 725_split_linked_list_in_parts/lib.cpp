#include <vector>

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

unsigned GetListLen(const ListNode* head) {
    unsigned len = 0;
    for (; head; head = head->next) {
        ++len;
    }
    return len;
}

std::vector<ListNode*> SplitList(ListNode* head, int parts) {
    std::vector<ListNode*> split;
    int len = GetListLen(head);
    for (; parts > 0; --parts) {
        split.push_back(head);
        int part_size = (len + parts - 1) / parts;
        if (part_size > 0) {
            for (int i = 0; i < part_size - 1; ++i) {
                head = head->next;
            }
            auto last = head;
            head = last->next;
            last->next = nullptr;
        }
        len -= part_size;
    }
    return split;
}

using std::vector;

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        return SplitList(head, k);
    }
};
