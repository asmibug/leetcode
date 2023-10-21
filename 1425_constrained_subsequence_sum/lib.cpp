#include <algorithm>
#include <cstddef>
#include <map>
#include <queue>
#include <stack>
#include <vector>

class MaxStack {
public:
    void push(int v) {
        stack_.push(v);
        maxs_.push(maxs_.empty() ? v : std::max(v, maxs_.top()));
    }

    int pop() {
        int res = stack_.top();
        stack_.pop();
        maxs_.pop();
        return res;
    }

    int max() const {
        return maxs_.top();
    }

    std::size_t size() const {
        return stack_.size();
    }

private:
    std::stack<int> stack_;
    std::stack<int> maxs_;
};

class MaxQueue {
public:
    void push(int v) {
        back_.push(v);
    }

    void pop() {
        if (!front_.size()) {
            while (back_.size()) {
                front_.push(back_.pop());
            }
        }
        front_.pop();
    }

    int max() const {
        int max;
        if (front_.size() && back_.size()) {
            max = std::max(front_.max(), back_.max());
        } else if (front_.size()) {
            max = front_.max();
        } else {
            max = back_.max();
        }
        return max;
    }

    std::size_t size() const {
        return front_.size() + back_.size();
    }

private:
    MaxStack front_;
    MaxStack back_;
};

class MaxQueueD {
public:
    void push(int v) {
        queue_.push(v);
        while (!maxs_.empty() && maxs_.back() < v) {
            maxs_.pop_back();
        }
        maxs_.push_back(v);
    }
    
    void pop() {
        int v = queue_.front();
        queue_.pop();
        if (maxs_.front() == v) {
            maxs_.pop_front();
        }
    }

    int max() const {
        return maxs_.front();
    }

    unsigned size() const {
        return queue_.size();
    }

private:
    std::queue<int> queue_;
    std::deque<int> maxs_;
};

template<typename Queue>
int GetMaxSumMaxQueue(const std::vector<int>& nums, int k) {
    int n = nums.size();

    int max_sum = nums[0];
    Queue maxs;
    maxs.push(max_sum);
    for (int i = 1; i < n; ++i) {
        int candidate = nums[i] + std::max(maxs.max(), 0);
        if (candidate > max_sum) {
            max_sum = candidate;
        }
        if (maxs.size() - k == 0) {
            maxs.pop();
        }
        maxs.push(candidate);
    }
    return max_sum;
}

int GetMaxSumHeap(const std::vector<int>& nums, int k) {
    int n = nums.size();

    int max_sum = nums[0];
    std::priority_queue<std::pair<int, int>> max_sums;
    if (max_sum > 0) {
        max_sums.push({max_sum, 0});
    }
    
    for (int i = 1; i < n; ++i) {
        while (!max_sums.empty() && i - max_sums.top().second > k) {
            max_sums.pop();
        }
        int candidate = nums[i]+ (max_sums.empty() ? 0 : max_sums.top().first);
        if (candidate > max_sum) {
            max_sum = candidate;
        }
        if (candidate > 0) {
            max_sums.push({candidate, i});
        }
    }
    return max_sum;
}

int GetMaxSumTree(const std::vector<int>& nums, int k) {
    int n = nums.size();

    int max_sum = nums[0];
    std::queue<int> queue;
    queue.push(max_sum);
    std::map<int, int> max_sums;
    if (max_sum > 0) {
        ++max_sums[max_sum];
    }

    for (int i = 1; i < n; ++i) {
        int candidate = nums[i] + (
            max_sums.empty() ? 0 : max_sums.rbegin()->first);
        if (candidate > max_sum) {
            max_sum = candidate;
        }
        if (queue.size() - k == 0) {
            if (queue.front() > 0) {
                auto it = max_sums.find(queue.front());
                --it->second;
                if (!it->second) {
                    max_sums.erase(it);
                }
            }
            queue.pop();
        }
        queue.push(candidate);
        if (candidate > 0) {
            ++max_sums[candidate];
        }
    }
    return max_sum;
}

int GetMaxSumMonotonousQueue(const std::vector<int>& nums, int k) {
    int n = nums.size();

    int max_sum = nums[0];
    std::deque<int> sums;
    std::deque<int> indices;
    if (max_sum > 0) {
        sums.push_back(max_sum);
        indices.push_back(0);
    }

    for (int i = 1; i < n; ++i) {
        if (!indices.empty() && i - indices.front() > k) {
            sums.pop_front();
            indices.pop_front();
        }
        int candidate = nums[i];
        if (!sums.empty()) {
            candidate += sums.front();
        }
        if (candidate > max_sum) {
            max_sum = candidate;
        }
        if (candidate > 0) {
            while (!sums.empty() && sums.back() <= candidate) {
                sums.pop_back();
                indices.pop_back();
            }
            sums.push_back(candidate);
            indices.push_back(i);
        }
    }
    return max_sum;
}

using std::vector;

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        return GetMaxSumMonotonousQueue(nums, k);
    }
};
