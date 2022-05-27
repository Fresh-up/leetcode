class Solution {
public:
    string minimizeResult(string expression) {
        string leftnum, rightnum;
        int lp = 0, rp = 0;
        int lnum = 0;
        while (expression[lnum] != '+') ++lnum;
        int rnum = expression.size() - lnum - 1;
        vector<vector<int>> dp;
        leftnum = expression.substr(0, lnum);
        rightnum = expression.substr(lnum + 1, rnum);
        for (int i = 0; i < lnum; ++i) {
            int mul1, add1;
            if (i == 0) {
                mul1 = 1;
                add1 = stoi(leftnum);
            } else {
                mul1 = stoi(leftnum.substr(0, i));
                add1 = stoi(leftnum.substr(i, lnum - i));
            }
            for (int j = 1; j <= rnum; ++j) {
                int mul2, add2;
                if (j == rnum) {
                    mul2 = 1;
                    add2 = stoi(rightnum);
                } else {
                    add2 = stoi(rightnum.substr(0, j));
                    mul2 = stoi(rightnum.substr(j, rnum - j));
                }
                dp.push_back({(add1 + add2) * mul1 * mul2, i, j});
            }
        }
        sort(dp.begin(), dp.end());
        expression.insert(dp[0][1], 1, '(');
        expression.insert(lnum + dp[0][2] + 2, 1, ')');
        return expression;
    }
};