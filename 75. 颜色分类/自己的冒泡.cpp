class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 冒泡
        for (int n = nums.size(); n > 0; --n){
            bubble(nums, n);
        }
    }
    void bubble(vector<int>& nums, int n){
        for (int i = 1; i < n; ++i){
            if (nums[i] < nums[i-1])
                swap(nums[i-1], nums[i]);
        }
    }
};
// O(n^2)  O(1)