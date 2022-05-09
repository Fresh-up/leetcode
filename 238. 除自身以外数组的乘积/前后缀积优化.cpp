class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, 1);
        int prefix = 1, suffix = 1;
        for (int i = 0; i < n; ++i) {
            ret[i] *= prefix;
            ret[n - 1 - i] *= suffix;
            prefix *= nums[i];
            suffix *= nums[n - 1 - i];
        }
        return ret;
    }
};
// O(n) O(1)