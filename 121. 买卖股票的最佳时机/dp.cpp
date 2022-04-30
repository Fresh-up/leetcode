class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int n = prices.size();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; ++i){
            mini = min(mini, prices[i]);
            dp[i] = max(dp[i-1], prices[i] - mini);
        }
        return dp[n - 1];
    }
};