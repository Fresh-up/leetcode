class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = n == 0 ? 0 : matrix[0].size();
        set<int> rows, cols;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == 0) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (rows.count(i) || cols.count(j)) matrix[i][j] = 0;
            }
        }
    }
};
// O(n^2) O(n)