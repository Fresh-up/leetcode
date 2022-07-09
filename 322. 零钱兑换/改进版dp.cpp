class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; ++i) {
            int mmin = INT_MAX;
            for (const auto& coin : coins) {
                if (i < coin) break;
                if (dp[i - coin] != -1)
                    mmin = min(dp[i - coin], mmin);
            }
            dp[i] = (mmin == INT_MAX) ? -1 : mmin + 1;
        }
        return dp[amount];
    }
};
