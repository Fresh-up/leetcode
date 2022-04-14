#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<char>> m{{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},
        {'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},
        {'w','x','y','z'}};
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (n == 0) return {};
        vector<string> ans;
        string temp;
        
        backtrack(digits, temp, ans, 0, n, digits[0] - '0');
        return ans;
    }
    void backtrack(string digits, string& temp, vector<string>& ans, 
        int cnt, const int n, int i){
        if (cnt == n){
            ans.emplace_back(temp);
            return;
        }
        for (int j = 0; j < m[i].size(); ++j){
            temp += m[i][j];
            ++cnt;
            backtrack(digits, temp, ans, cnt, n, digits[cnt] - '0');
            --cnt;
            temp.erase(temp.size() - 1);
            // 可以用pop_back()
        }
    }
};
//前段回溯学得不错，这道题一遍就做出来了
//时间复杂度O(3^m x 4^n)其中 m 是输入中对应 3 个字母的数字个数
//（包括数字 2、3、4、5、6、8），n 是输入中对应 4 个字母的数字个数
//（包括数字 7、9），m+n 是输入数字的总个数。
//当输入包含 m 个对应 3 个字母的数字和 n 个对应 4 个字母的数字时，
//不同的字母组合一共有3^m x 4^n种
//空间复杂度O(m+n)