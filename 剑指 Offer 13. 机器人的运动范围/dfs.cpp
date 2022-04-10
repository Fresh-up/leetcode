#include <vector>
using namespace std;
//一开始理解错了，以为机器人可以从任意位置放下，然后遍历整个表
class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    int movingCount(int m, int n, int k) {
        int gex = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        dfs(gex, vis, 0, 0, k);
        return gex;
    }
    int numsum(int n){
        int sum = 0, m;
        m = n;
        while (m != 0){
            n = m % 10;
            m = m / 10;
            sum += n;
        }
        return sum;
    }
    void dfs(int& gex, vector<vector<bool>>& vis, int i, int j, int limit){
        if (vis[i][j]) return;
        vis[i][j] = true;
        ++gex;
        int x, y;
        for (int k = 0; k < 4; ++k){
            x = i + direction[k], y = j + direction[k+1];
            int s = numsum(x) + numsum(y);
            if (x >= 0 && x < vis.size() && 
                y >= 0 && y < vis[0].size() && 
                !vis[x][y] && s <= limit)
                dfs(gex, vis, x, y, limit);
        }
    }
};
//O(n) O(n)