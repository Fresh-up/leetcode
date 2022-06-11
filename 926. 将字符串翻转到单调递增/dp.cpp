class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int num1 = 0;
        int dp0 = 0, dp1 = 0;
        vector<int> dp(n + 1);
        for (const char& c : s) {
            if (c == '1') {
                ++num1;
                dp1 = dp0;
            } else {
                if (num1 != 0) {
                    dp1 = min(++dp0, num1);
                    dp0 = dp1;
                }
                else dp1 = dp0;
            }
        }
        return dp1;
    }
};
// O(n) O(1)简单动态规划
// 经验：应该先试几个例子，搭好基本框架，然后调试逐步完善代码