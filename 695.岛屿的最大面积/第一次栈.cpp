class Solution {
public:
    //用direction可以搜索一个位置的四个方向
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0;
        int x, y, c, r, local_area, max_area = 0;
        vector<int> direction{-1, 0, 1, 0, -1};
        //stack<pair<int, int>> island;
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (grid[i][j]){
                    local_area = 1;//!相当于重置的作用
                    grid[i][j] = 0;
                    stack<pair<int, int>> island;//!遍历每个格创建一次栈
                    island.push({i, j});
                    while(!island.empty()){
                        auto [r, c] = island.top();
                        island.pop();//记住当用到栈顶的时候，弹出

                        for (int k = 0; k < 4; ++k){
                            x = r + direction[k], y = c + direction[k+1];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y]){
                                grid[x][y] = 0;
                                ++local_area;
                                island.push({x, y});
                            }
                        }

                    }
                }
                max_area = max(max_area, local_area);
            }
        }
        return max_area;
    }
};
//24ms 24.22%
//26MB 18.10%
//每个格只访问一次时间复杂度O(M*N) 空间复杂度O(M*N)