class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 双指针，i遍历，j永远指向第一个0的下标
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                if (j < i) {
                    nums[j] = nums[i];
                    nums[i] = 0;
                }
                ++j;
            } 
        }
    }
};
// O(n) O(1)