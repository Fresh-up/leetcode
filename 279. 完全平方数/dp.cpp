class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int sq = sqrt(i);
            for (int j = 1; j <= sq; ++j) {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
        return dp[n];
    }
};
// O(n开方n) O(n)