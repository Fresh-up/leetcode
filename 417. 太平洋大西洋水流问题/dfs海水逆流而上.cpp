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
            dfs(heights, i, 0, reachp);//从矩阵的左边入手
            dfs(heights, i, n-1, reacha);//从矩阵的右边入手
        }
        for (int j = 0; j < n; ++j){
            dfs(heights, 0, j, reachp);//从矩阵的上边入手
            dfs(heights, m-1, j, reacha);//从矩阵的下边入手
        }
        //对两个可达矩阵取交集，即海水可以倒流到的点
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
        if(canreach[i][j]){//true false矩阵每个节点隐含着两层意思
        //一，这个点可以流入一个海洋    二，这个点已经被访问过
            return;
        }
        canreach[i][j] = true;
        int x, y;

        //开始向四周搜索
        for (int k = 0; k < 4; ++k){
            x = i + direction[k], y = j + direction[k+1];
            if (x >= 0 && x < heights.size() && 
                y >= 0 && y < heights[0].size() && 
                heights[x][y] >= heights[i][j])//别忘了等号
                //能进入下一个递归的，就已经说明海水已经可以倒流到即将要递归的这个点的
                dfs(heights, x, y, canreach);
        }
    }
};