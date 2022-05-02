class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i){
            auto iter = mp.find(target - nums[i]);
            if (iter != mp.end())
                return {iter->second, i};
            mp[nums[i]] = i;
        }
        return {};
    }
};