class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long ans = 0;
        unordered_map<int, int> mymap;
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);
        for (const auto& road : roads) {
            for (int i = 0; i < 2; ++i) {
                ++mymap[road[i]];
            }
        }
        sort(id.begin(), id.end(), [&](int i, int j) { return mymap[i] < mymap[j]; });
        for (int i = 0; i < n; ++i) {
            mymap[id[i]] = i + 1;
        }
        for (const auto& road : roads) {
            for (int i = 0; i < 2; ++i) {
                ans += mymap[road[i]];
            }
        }
        return ans;
    }
};