class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        auto assist = matrix;// 值拷贝
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                assist[j][n - i - 1] = matrix[i][j];
            }
        }
        matrix = assist;// 值拷贝
    }
};
// O(n^2) O(n^2)