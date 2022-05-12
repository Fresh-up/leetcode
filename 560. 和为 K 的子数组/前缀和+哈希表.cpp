class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ret = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        int pre = 0;
        mp[0] = 1;
        for (int i = 0; i < n; ++i) {
            pre += nums[i];
            if (mp.count(pre - k)) ret += mp[pre - k];
            ++mp[pre];// 一定要在判断之后，这个哈希值才+1
            // 反例[1] k=0
        }
        return ret;
    }
};
// O(n) O(n)