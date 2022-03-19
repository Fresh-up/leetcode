class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        //用一个哈希表记录上次搜索到的该字符的位置
        unordered_map<char, int> mymap;
        int n = s.size();
        //用一个数组来记录以当前位置下的元素结尾的，最大子串长度
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        mymap[s[0]] = 0;
        int maxlen = 1;
        for (int i = 1; i < n; ++i){
            if (!mymap.count(s[i])){
                dp[i] = dp[i-1] + 1;
            }
            else {
                int tolast = i - mymap[s[i]];
                if (tolast <= dp[i-1]){
                    dp[i] = tolast;
                }
                else {
                    dp[i] = dp[i-1] + 1;
                }
            }
            mymap[s[i]] = i;
            maxlen = max(maxlen, dp[i]);
        }
        return maxlen;
    }
};
//16ms 68.44%
//8.7MB 51.56%
//时间复杂度，只遍历一遍O(n)
//空间复杂度，O(n)

//空间优化版
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        //用一个哈希表记录上次搜索到的该字符的位置
        unordered_map<char, int> mymap;
        int n = s.size();
        //用一个数组来记录以当前位置下的元素结尾的，最大子串长度
        //vector<int> dp(n + 1, 0);
        int pre = 1;
        mymap[s[0]] = 0;
        int maxlen = 1;
        for (int i = 1; i < n; ++i){
            if (!mymap.count(s[i])){
                pre = pre + 1;
            }
            else {
                int tolast = i - mymap[s[i]];
                if (tolast <= pre){
                    pre = tolast;
                }
                else {
                    pre = pre + 1;
                }
            }
            mymap[s[i]] = i;
            maxlen = max(maxlen, pre);
        }
        return maxlen;
    }
};
//空间复杂度O(1)