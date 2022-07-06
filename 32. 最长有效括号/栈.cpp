class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        stk.push(-1);
        int m = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    stk.pop();
                    if (stk.empty()) { 
                        stk.push(i);
                    } else {
                        m = max(i - stk.top(), m);
                    }
                }
            }
        }
        return m;
    }
};
// O(n) O(n)