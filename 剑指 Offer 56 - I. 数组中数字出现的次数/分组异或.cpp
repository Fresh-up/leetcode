// 设其中只出现一遍的数字为a和b
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int k = 0;// k最终是a和b异或的结果
        int left = 0, right = 0;
        int p = 0;
        for (const auto& num : nums) k ^= num;

        for (; p <= 31; ++p) if (k >> p & 1) break;
        // 用k找到a和b第一个不同的数位，即k第一个非零的数位，记为p

        for (const auto& num : nums) {
            // 以第p位不同，把数组分组，a和b一定在不同的组里面
            if (num >> p & 1) left ^= num;
            else right ^= num;
        }
        return vector<int>{left, right};
    }
};
// O(n) O(1)