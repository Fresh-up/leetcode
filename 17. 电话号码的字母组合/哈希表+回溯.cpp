#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    unordered_map<char, string> phoneMap{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (n == 0) return {};
        vector<string> ans;
        string temp;
        
        backtrack(digits, temp, ans, 0, n);
        return ans;
    }
    void backtrack(string digits, string& temp, vector<string>& ans, 
        int cnt, const int n){
        if (cnt == n){
            ans.emplace_back(temp);
            return;
        }
        string line = phoneMap[digits[cnt]];
        for (const char& letter : line){
            temp.push_back(letter);
            ++cnt;
            backtrack(digits, temp, ans, cnt, n);
            --cnt;
            temp.pop_back();
        }
        
    }
};
//O(n) O(n)
//前段回溯学得不错，这道题一遍就做出来了