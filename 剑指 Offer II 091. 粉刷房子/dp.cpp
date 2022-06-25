// 找到最优子结构是关键
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0] = costs[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + costs[i][2];
        }
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
// O(n) O(n)