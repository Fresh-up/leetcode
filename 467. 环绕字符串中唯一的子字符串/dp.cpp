class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int res = 0;
        vector<int> dp(26, 0);// 记录以每个字母结尾的合法子串的数量
        for (int i = 0; i < p.size(); ++i) {
            // 符合条件：当前元素跟前一个元素是相邻的，或者是a和z
            // 如果不符合，则子字符串是单独一个字母，也合法
            if ((i != 0) && (p[i] - p[i - 1] + 26) % 26 == 1) ++res;
            else res = 1;
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], res);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
// O(n) O(n)