class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int d0 = -prices[0];
        int d1 = 0, d2 = 0, t;
        for (int i = 1; i < n; ++i) {
            t = d1;
            d1 = d0 + prices[i];
            d0 = max(d0, d2 - prices[i]);
            d2 = max(t, d2);
        }
        return max(d1, d2);
    }
};
// O(n) O(1)