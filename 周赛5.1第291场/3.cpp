/*
考虑错误的点：
1.以为至少要包含一个可以整除p的元素，实际上可以没有
2.没有考虑到去重
3.看到数组元素少于200就以为用dp，结果还可以暴力

正确思路：枚举所有子数组，判断是否符合要求，再用set去重，复杂度
O(n*n*n)(一共O(n*n)的子数组，每个子数组放进set长度是O(n))
*/

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        unordered_set<string> st;

        for (int i = 0; i < n; ++i){
            string t;
            int cnt = 0;
            for (int j = i; j < n; ++j){
                if (nums[j] % p == 0) ++cnt;
                if (cnt > k) break;
                // 加"|"的作用是防止因为多个数位叠加而产生的重叠
                // 比如[3,2,1]推进string为"321",而[3,21]推进string也是"321"
                t += to_string(nums[j]) + "|";// 别忘了+=
                st.insert(t);
            }
        }
        return st.size();
    }
};

// 自己写的错误代码
// class Solution {
// public:
//     int countDistinct(vector<int>& nums, int k, int p) {
//         int n = nums.size();
//         vector<int> dp(n + 1, 0);
//         vector<int> mark;
//         int cnt = 0;

//         for (int i = 1; i <= n; ++i){
//             if (nums[i - 1] % p != 0){
//                 dp[i] = dp[i - 1] + i;
//             }
//             else {
//                 mark.emplace_back(i - 1);
//                 int tmp = mark.size() - 1;
//                 if (cnt < k){
//                     ++cnt;
//                     dp[i] = dp[i - 1] + mark[tmp] - mark[0] + 1;
//                 }
//                 else {
//                     dp[i] = dp[i - 1] + mark[tmp] - mark[tmp - k];
//                 }
//             }
//         }
//         return dp[n];
//     }
// };