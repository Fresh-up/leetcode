/*
思路：
把连续的重复字符串转化为一个个区间，然后按字典序遍历这些区间，
如果两区间只隔了一个字符，则可以相连，相连有两种情况，
一种是有第三个区间，另一种这个字符只有两个区间
*/

class Solution {
public:
    int maxRepOpt1(string s) {
        vector<vector<pair<int, int>>> v(26);
        int l = 0, r = 0, res = 0;
        while (l < s.size()) {
            r = l;
            while (r + 1 < s.size() && s[r + 1] == s[l]) ++r;
            v[s[l] - 'a'].push_back({l, r - l + 1}); // first是起始下标，second是长度
            l = r + 1;
        }

        for (int i = 0; i < 26; ++i) {
            if (v[i].empty()) continue;
            res = max(res, v[i][0].second);
            for (int j = 1; j < v[i].size(); ++j) {
                if (v[i][j - 1].first + v[i][j - 1].second + 1 == v[i][j].first)
                    // 如果有三段，则可以从第三段拿一个元素置换中间元素，使两段相连
                    // 如果没有三段，只有两段，则从第二段末尾拿一个元素置换中间元素，得到还是两段长度和
                    res = max(res, v[i][j - 1].second + v[i][j].second + (v[i].size() >= 3));
                else res = max(res, v[i][j].second);
            }
        }
        return res;
    }
};
// O(n) O(n)