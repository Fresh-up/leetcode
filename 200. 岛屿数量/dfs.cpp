class Solution {
public:
    vector<int> directions{-1, 0, 1, 0, -1};
    int num = 0;
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = n == 0? 0 : grid[0].size();
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (grid[i][j] == '1'){
                    dfs(grid, i, j);
                    ++num;
                }
            }
        }
        return num;
    }
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m){
        if (grid[i][j] == '0') return;
        grid[i][j] = '0';
        for (int k = 0; k < 4; ++k){
            int x = i + directions[k], y = j + directions[k + 1];
            if (x >= 0 && y >= 0 && x < n && y < m)// 注意要有这个判断数组越界
                dfs(grid, x, y);
        }
    }
};
// O(nm) O(nm)最坏情况下所有都是陆地，所以nm空间复杂度