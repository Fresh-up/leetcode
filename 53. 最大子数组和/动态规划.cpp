// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         if (nums.size() == 1) return nums[0];
//         int maxsum = 0;// 万一数组全为负数就会出问题，所以必须选一个
//         int n = nums.size();
//         // premax表示以当前元素前一个元素结尾的最大子和
//         // int premax = max(nums[0], 0);// 第一个可以不选
//         int premax = nums[0];// 因为你从1开始遍历，所以默认要选第一个
//         for (int i = 1; i < n; ++i){
//             // maxsum = max(premax + nums[i], nums[i]);
//             // premax = maxsum;
//             premax = max(premax + nums[i], nums[i]);
//             maxsum = max(maxsum, premax);
//         }
//         return maxsum;
//     }
// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int premax = 0; // 从数组外开始
        int maxsum = nums[0];
        for (const int& x : nums){
            premax = max(premax + x, x);
            maxsum = max(maxsum, premax);
        }
        return maxsum;
    }
};
// O(n) O(1)