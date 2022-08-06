class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp;
        for (const auto& it : items1) {
            mp[it[0]] = it[1];
        }
        for (const auto& it : items2) {
            if (!mp.count(it[0])) mp[it[0]] = it[1];
            else mp[it[0]] += it[1];
        }
        vector<vector<int>> ans;
        auto it = mp.begin();
        while (it != mp.end()) {
            vector<int> t{it->first, it->second};
            ans.emplace_back(t);
            it++;
        }
        return ans;
    }
};