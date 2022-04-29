class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> myset;
        for (const auto& word : wordDict) myset.insert(word);

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i){
            for (int j = 0; j < i; ++j){
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