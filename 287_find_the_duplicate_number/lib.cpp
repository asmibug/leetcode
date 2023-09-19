#include <vector>

int FindDuplicateFloyd(const std::vector<int>& nums) {
    int slow = 0;
    int fast = nums[slow];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
        fast = nums[fast];
    }
    slow = 0;
    int tail = nums[fast];
    while (slow != tail) {
        slow = nums[slow];
        tail = nums[tail];
    }
    return slow;
}

int FindDuplicateBrent(const std::vector<int>& nums) {
    int pow_of_2 = 1;
    int cycle_len = 1;
    int current = 0;
    int next = nums[current];
    while (next != current) {
        ++cycle_len;
        if (cycle_len > pow_of_2) {
            pow_of_2 *= 2;
            cycle_len = 1;
            current = next;
        }
        next = nums[next];
    }
    current = 0;
    next = current;
    for (int i = 0; i < cycle_len; ++i) {
        next = nums[next];
    }
    while (current != next) {
        current = nums[current];
        next = nums[next];
    }
    return current;
}

using std::vector;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        return FindDuplicateBrent(nums);
    }
};
