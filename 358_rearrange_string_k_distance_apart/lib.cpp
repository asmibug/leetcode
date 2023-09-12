#include <algorithm>  // std::max_element
#include <deque>  // std::deque
#include <queue>  // std::priority_queue
#include <string>  // std::string

std::string RearrangeStringHeap(const std::string& s, int min_distance) {
    if (min_distance <= 1) {  // then there's nothing to do
        return s;
    }

    constexpr unsigned counts_len = 'z' - 'a' + 1;
    unsigned counts[counts_len] = {0};
    for (char c : s) {
        ++counts[c - 'a'];
    }

    unsigned indices[counts_len];
    for (unsigned i = 0; i < counts_len; ++i) {
        indices[i] = i;
    }
    auto cmp = [&counts](unsigned i, unsigned j) {
        return counts[i] < counts[j];
    };
    std::priority_queue<unsigned, std::vector<unsigned>, decltype(cmp)> queue( 
        indices, indices + counts_len, cmp
    );
    std::deque<unsigned> used;

    std::string res;
    res.reserve(s.size());
    for (unsigned i = 0; i < s.size(); ++i) {
        if (used.size() >= static_cast<unsigned>(min_distance)) {
            queue.push(used.front());
            used.pop_front();
        }
        if (queue.empty() || counts[queue.top()] == 0) {
            return "";
        }
        unsigned index = queue.top();
        queue.pop();
        char symbol = 'a' + index;
        res.push_back(symbol);
        --counts[index];
        used.push_back(index);
    }
    return res;
}

std::string RearrangeStringGreedy(const std::string& s, int min_distance) {
    if (min_distance <= 1) {
        return s;
    }

    constexpr unsigned counts_len = 'z' - 'a' + 1;
    unsigned counts[counts_len] = {0};
    for (char c : s) {
        ++counts[c - 'a'];
    }

    unsigned max_count = *std::max_element(&counts[0], &counts[counts_len]);
    std::vector<std::string> segments(max_count);
    for (unsigned i = 0; i < counts_len; ++i) {
        char symbol = 'a' + i;
        if (counts[i] == max_count) {
            for (unsigned j = 0; j < counts[i]; ++j) {
                segments[j].push_back(symbol);
            }
        }
    }
    for (unsigned i = 0; i < counts_len; ++i) {
        char symbol = 'a' + i;
        if (counts[i] == max_count - 1) {
            for (unsigned j = 0; j < counts[i]; ++j) {
                segments[j].push_back(symbol);
            }
        }
    }
    unsigned segment_idx = 0;
    for (unsigned i = 0; i < counts_len; ++i) {
        if (counts[i] >= max_count - 1) {
            continue;
        }
        char symbol = 'a' + i;
        for (unsigned j = 0; j < counts[i]; ++j) {
            segments[segment_idx].push_back(symbol);
            segment_idx = (segment_idx + 1) % (max_count - 1);
        }
    }

    std::string result;
    for (unsigned i = 0; i < segments.size() - 1; ++i) {
        if (segments[i].size() < static_cast<unsigned>(min_distance)) {
            return "";
        }
        result += segments[i];
        segments[i] = "";
    }
    result += segments.back();
    return result;
}

using std::string;

class Solution {
public:
    string rearrangeString(string s, int k) {
        return RearrangeStringGreedy(s, k);
    }
};
