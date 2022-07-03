class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<int> dir{0, 1, 0, -1, 0};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = 0;
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (dp[i][j] != -1) return dp[i][j];
            int res = 0;
            for (int k = 0; k < 4; ++k) {
                int x = dir[k] + i, y = dir[k + 1] + j;
                if (x >= 0 && y >= 0 && x < m && y < n && matrix[i][j] < matrix[x][y]) {
                    res = max(res, dfs(x, y));
                }
            }
            return dp[i][j] = res + 1;
        };
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                ans = max(ans, dfs(i, j));
        return ans;
    }
};
// O(mn) O(mn)