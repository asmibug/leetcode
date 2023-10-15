#include <algorithm>
#include <vector>

long long GetMaxBooks(const std::vector<int>& books) {
    int n = books.size();
    std::vector<long long> count_if_end_on_idx;
    count_if_end_on_idx.reserve(n);
    std::vector<int> increasing_indices;
    increasing_indices.reserve(n);
    for (int i = 0; i < n; ++i) {
        while (!increasing_indices.empty()
               && (books[increasing_indices.back()]
                   + i - increasing_indices.back()) > books[i]) {
            increasing_indices.pop_back();
        }
        long long prev;
        int range;
        if (!increasing_indices.empty()) {
            prev = count_if_end_on_idx[increasing_indices.back()];
            range = i - increasing_indices.back();
        } else {
            prev = 0;
            range = std::min(i + 1, books[i]);
        }
        count_if_end_on_idx.push_back(
            prev + 1LL * range * (2 * books[i] - range + 1) / 2);
        increasing_indices.push_back(i);
    }
    return *std::max_element(count_if_end_on_idx.begin(),
                             count_if_end_on_idx.end());
}

using std::vector;

class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        return GetMaxBooks(books);
    }
};
