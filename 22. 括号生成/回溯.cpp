class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        backtrack(ans, 0, 0, n, cur);
        return ans;
    }
    // 一般回溯不再用for循环
    void backtrack(vector<string>& ans, int open, int close, 
        int n, string& cur){
        if (cur.size() == 2 * n){
            ans.emplace_back(cur);
            return;
        }
        if (open < n){
            cur.push_back('(');
            backtrack(ans, open + 1, close, n, cur);
            cur.pop_back();
        }
        if (close < open){
            cur.push_back(')');
            backtrack(ans, open, close + 1, n, cur);
            cur.pop_back();
        }
    }
};
//时间复杂度太难算，空间复杂度O(n)