class Solution {
    short dir[4][2]{0, 1, 1, 0, 0, -1, -1, 0};
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, -1));
        int k = 1, nn = n * n;
        int i = 0, j = 0, D = 0;
        while (k <= nn) {
            ans[i][j] = k++;
            int ii = i + dir[D][0], jj = j + dir[D][1];
            if (ii < 0 || ii >= n || jj < 0 || jj >= n || ans[ii][jj] != -1) 
                D = (D + 1) % 4;
            i += dir[D][0];
            j += dir[D][1];
        }
        return ans;
    }
};