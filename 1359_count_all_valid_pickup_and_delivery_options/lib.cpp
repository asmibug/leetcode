int CountOrders(int n) {
    auto count = 1ull;
    for (int i = 1; i < n; ++i) {
        unsigned places = 2 * i + 1;
        unsigned combinations = places * (places + 1) / 2;
        count *= combinations;
        count %= 1'000'000'007;
    }
    return count;
}

class Solution {
public:
    int countOrders(int n) {
        return CountOrders(n);
    }
};
