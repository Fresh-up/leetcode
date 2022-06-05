class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> mymap;
        for (int i = 0; i < nums.size(); ++i) mymap[nums[i]] = i;
        for (const auto& op : operations) {
            nums[mymap[op[0]]] = op[1];
            mymap[op[1]] = mymap[op[0]];
            mymap.erase(op[0]);
        }
        return nums;
    }
};