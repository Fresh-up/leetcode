class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int top = 0;
        int n = grid.size();
        vector<int> f(n, 0);
        vector<int> s(n, 0);
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                int tmp = grid[i][j];
                f[j] = max(tmp, f[j]);
                s[i] = max(tmp, s[i]);
                if (tmp != 0) ++top;
            }
        }

        return top + accumulate(f.begin(), f.end(), 0) + 
            accumulate(s.begin(), s.end(), 0);

    }
};
//O(n^2) O(n)