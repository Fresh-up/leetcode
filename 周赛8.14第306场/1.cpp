class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n - 2, vector<int>(n - 2, 0));
        function<void(int, int)> func = [&](int row, int col) {
            int mmax = 0;
            for (int i = row; i < row + 3; ++i) 
                for (int j = col; j < col + 3; ++j) 
                    mmax = max(mmax, grid[i][j]);
            ans[row][col] = mmax;
        };
        for (int i = 0; i <= n - 3; ++i) {
            for (int j = 0; j <= n - 3; ++j)
                func(i, j);
        }
        return ans;
    }
};