class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int n = grid.size(), m = n == 0 ? 0 : grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[n][m];
    }
};
// O(n*m) O(n*m)