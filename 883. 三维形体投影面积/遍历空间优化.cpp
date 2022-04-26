class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int top = 0, front = 0, side = 0;
        int n = grid.size();
        for (int i = 0; i < n; ++i){
            int tmpf = 0, tmps = 0;
            for (int j = 0; j < n; ++j){
                // 这步我是没想到，纵向遍历
                tmpf = max(tmpf, grid[j][i]);
                tmps = max(grid[i][j], tmps);
                top += grid[i][j] != 0 ? 1 : 0;
            }
            side += tmps;
            front += tmpf;
        }
        return top + front + side;
    }
};
// O(n^2) O(1)
// 总结：遍历二维空间时，可更换i,j实现纵向遍历；多用? :减少if