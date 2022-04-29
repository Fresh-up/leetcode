// 遍历分割点时，倒着遍历，当长度超过字典里单词最长的长度时，停止遍历
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> myset;
        int maxw = 0;
        for (const auto& word : wordDict) {
            myset.insert(word);
            maxw = max(maxw, (int)word.size());
        }

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i){
            for (int j = i - 1; j >= i - maxw; --j){
                if (dp[j] && myset.find(s.substr(j, i - j)) != myset.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
// O(n^2) O(n)
// maxw = max(maxw, (int)word.size());一定要加(int)，否则编译不通过