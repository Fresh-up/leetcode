// 记忆化搜索，我们可以遍历每个格子，以这个格子为起点，往4个方向前进
// 如果下一个格子比当前格子大，则前进，dp[i][j]是邻近四个格子的dp累加，
// 在加上1，一个问题：邻近的四个格子的dp值包含当前格子的路径吗？
// 不会，因为题目条件是递增路径，所以是单向的。
class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> dir{0, 1, 0, -1, 0};
    int m, n;
    int countPaths(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                ans = (ans + dfs(i, j, grid, dp)) % MOD;
        return ans;
    }
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (dp[i][j] != -1) return dp[i][j];
        int res = 1;
        for (int k = 0; k < 4; ++k) {
            int x = dir[k] + i, y = dir[k + 1] + j;
            if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] > grid[i][j]) 
                res = (res + dfs(x, y, grid, dp)) % MOD;
        }
        return dp[i][j] = res;
    }
};
// O(mn) O(mn)

// 试试用C++新特性来做，减少函数形参的个数
class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> dir{0, 1, 0, -1, 0};
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        function<int(int, int)> dfs = [&](int i, int j) {
            if (dp[i][j] != -1) return dp[i][j];
            int res = 1;
            for (int k = 0; k < 4; ++k) {
                int x = dir[k] + i, y = dir[k + 1] + j;
                if (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] > grid[i][j]) 
                    res = (res + dfs(x, y)) % MOD;
            }
            return dp[i][j] = res;
        };
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                ans = (ans + dfs(i, j)) % MOD;
        return ans;
    }
};