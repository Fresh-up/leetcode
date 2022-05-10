class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int mmax = amount + 1;
        vector<int> dp(mmax, mmax);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] <= i)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] > amount? -1 : dp[amount];
    }
};
// O(Sn) S为金额，n为面额数，一共要计算S个状态的答案，对于每个状态，
// 每次需要枚举n个面额来转移状态，所以一共要O(Sn)的时间复杂度
// O(S)