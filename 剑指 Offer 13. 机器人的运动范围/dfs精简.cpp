#include <vector>
using namespace std;
//一开始理解错了，以为机器人可以从任意位置放下，然后遍历整个表
//因为机器人从[0, 0]开始，所以只用向下向右搜索即可
class Solution {
public:
    //vector<int> direction{-1, 0, 1, 0, -1};
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
        if (i < 0 || i >= vis.size() || 
            j < 0 || j >= vis[0].size() || vis[i][j]) return;
        int s = numsum(i) + numsum(j);
        if (s > limit) return;
        vis[i][j] = true;
        ++gex;
        dfs(gex, vis, i + 1, j, limit);
        dfs(gex, vis, i, j + 1, limit);
    }
};