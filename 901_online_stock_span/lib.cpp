/**
 * https://leetcode.com/problems/online-stock-span/
 * 
 * Approaches:
 * 1) Brute-force: O(n)
 * 2) Tree-map: keep (value -> span): O(n log n)
 * 2.1) Heap instead of tree-map with (value, span): O(n log n)
 * 3) Decreasing stack: keep (value, span): O(n)
 * 4) Hash-map: for each element store next greater and span
 * 
 * Instead of span we can store index, but we'll need to keep additional field
*/

#include <limits>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>

class StockSpannerBruteForce {
public:
    StockSpannerBruteForce() = default;
    
    int next(int price) {
        prices_[idx_++] = price;
        int span = 0;
        for (int i = idx_ - 1; i >= 0 && prices_[i] <= price; --i) {
            ++span;
        }
        return span;
    }

private:
    static constexpr int kMaxSize = 1e4;
    static int prices_[kMaxSize];
    int idx_ = 0;
};

int StockSpannerBruteForce::prices_[kMaxSize];


class StockSpannerMap {
public:
    StockSpannerMap() = default;
    
    int next(int price) {
        int span = 1;
        while (!price2span_.empty() && price2span_.begin()->first <= price) {
            span += price2span_.begin()->second;
            price2span_.erase(price2span_.begin());
        }
        price2span_[price] = span;
        return span;
    }

private:
    std::map<int, int> price2span_;
};


template <typename Adaptor>
class StockSpannerAdaptor {
public:
    StockSpannerAdaptor() = default;
    
    int next(int price) {
        int span = 1;
        while (!price_span_.empty() && price_span_.top().first <= price) {
            span += price_span_.top().second;
            price_span_.pop();
        }
        price_span_.push({price, span});
        return span;
    }

private:
    Adaptor price_span_;
};

using p = std::pair<int, int>;
using StockSpannerHeap = StockSpannerAdaptor<
    std::priority_queue<p, std::vector<p>, std::greater<p>>>;
using StockSpannerStack = StockSpannerAdaptor<std::stack<p>>;


class StockSpannerHash {
public:
    StockSpannerHash() = default;
    
    int next(int price) {
        int span = 1;
        while (prev_ <= price) {
            int new_prev = prev_and_span_[prev_].first;
            span += prev_and_span_[prev_].second;
            prev_and_span_.erase(prev_);
            prev_ = new_prev;
        }
        prev_and_span_[price] = {prev_, span};
        prev_ = price;
        return span;
    }

private:
    std::unordered_map<int, std::pair<int, int>> prev_and_span_;
    int prev_ = std::numeric_limits<int>::max();
};


using StockSpanner = StockSpannerStack;

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
