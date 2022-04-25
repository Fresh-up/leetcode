// 比较简单
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_map<int, int> mymap;
        vector<int> vec;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < nums[i].size(); ++j){
                ++mymap[nums[i][j]];
            }
        }
        for (auto i = mymap.begin(); i != mymap.end(); ++i){
            if (i->second == n) vec.emplace_back(i->first);
        }
        sort(vec.begin(), vec.end());
        return vec;
    }
};