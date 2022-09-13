class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> ans(n, 0);
        long long cmp = -1;
        int resind = -1;
        for (int i = 0; i < n; ++i) {
            ans[edges[i]] += i;
            long long t = ans[edges[i]];
            if (t > cmp) {
                cmp = t;
                resind = edges[i];
            } else if (t == cmp) {
                resind = min(resind, edges[i]);
            }
        }
        return resind;
    }
};