#include <vector>
using namespace std;
/*
如果按遍历顺序来的话，不剪枝，复杂度会很大。
反过来想，海水倒流，从四边入手，再找交集
*/
class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};

        vector<vector<int>> place;
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> reachp(m, vector<bool>(n, false));
        vector<vector<bool>> reacha(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i){
            dfs(heights, i, 0, reachp);
            dfs(heights, i, n-1, reacha);
        }
        for (int j = 0; j < n; ++j){
            dfs(heights, 0, j, reachp);
            dfs(heights, m-1, j, reacha);
        }
        for (int i = 0; i < m; ++i){
            for (int j = 0; j < n; ++j){
                if (reacha[i][j] && reachp[i][j]){
                    //vector<int> vec{i, j};
                    //place.emplace_back(vec);
                    place.emplace_back(vector<int>{i, j});//!
                }
            }
        }
        return place;
    }
    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& canreach){
        if(canreach[i][j]){
            return;
        }
        canreach[i][j] = true;
        int x, y;
        for (int k = 0; k < 4; ++k){
            x = i + direction[k], y = j + direction[k+1];
            if (x >= 0 && x < heights.size() && 
                y >= 0 && y < heights[0].size() && 
                heights[x][y] >= heights[i][j])//别忘了等号
                dfs(heights, x, y, canreach);
        }
    }
};