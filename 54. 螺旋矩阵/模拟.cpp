class Solution {
    short dir[4][2]{0, 1, 1, 0, 0, -1, -1, 0};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        int k = 1, nn = m * n;
        int i = 0, j = 0, d = 0;
        while (k <= nn) {
            ans.emplace_back(matrix[i][j]);
            matrix[i][j] = 101;
            ++k;
            int ii = i + dir[d][0], jj = j + dir[d][1];
            if (ii < 0 || ii >= m || jj < 0 || jj >= n || matrix[ii][jj] == 101) 
                d = (d + 1) % 4;
            i += dir[d][0];
            j += dir[d][1];
        }
        return ans;
    }
};