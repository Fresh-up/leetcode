class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpmax(n, 0), dpmin(n, 0);
        dpmax[0] = nums[0], dpmin[0] = nums[0];
        for (int i = 1; i < n; ++i){
            dpmax[i] = max(dpmax[i-1] * nums[i], max(nums[i], dpmin[i-1] * nums[i]));
            dpmin[i] = min(dpmin[i-1] * nums[i], min(nums[i], dpmax[i-1] * nums[i]));
        }
        return *max_element(dpmax.begin(), dpmax.end());
    }
};
// O(n) O(n)