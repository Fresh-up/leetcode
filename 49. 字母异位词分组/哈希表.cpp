class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mymap;
        for (const string& s : strs){
            string ss = s;
            sort(ss.begin(), ss.end());
            mymap[ss].emplace_back(s);
        }
        vector<vector<string>> res;
        for (auto it = mymap.begin(); it != mymap.end(); ++it){
            res.emplace_back(it->second); // it->second
        }
        return res;
    }
};