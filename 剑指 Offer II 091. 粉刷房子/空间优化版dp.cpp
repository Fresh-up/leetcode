class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int c0 = 0, c1 = 0, c2 = 0;
        for (const auto& cost : costs) {
            int t0, t1, t2;
            t0 = min(c1, c2) + cost[0];
            t1 = min(c0, c2) + cost[1];
            t2 = min(c0, c1) + cost[2];
            c0 = t0, c1 = t1, c2 = t2;
        }
        return min(c0, min(c1, c2));
    }
};