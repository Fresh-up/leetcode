/* 首先要知道一个子问题怎么解：
如何判断一个字符串是不是另一个字符串的子串？
(字符串A可以删除其中某些字符(也可以不删除)，而得到字符串B，则B是A的子串)

bool subseq(string& sub, string& org) {
    int pts = 0, pto = 0;
    while (pts < sub.size() && pto < org.size()) {
        if (sub[pts] == org[pto]) ++pts;
        ++pto;
    }
    return pts == sub.size();
}
*/

/*
对于给定的某个字符串str[i]，如果它的一个子序列 sub 是「特殊序列」，
那么 str[i] 本身也是一个「特殊序列」。

这是因为如果 sub 如果没有在除了 str[i] 之外的字符串中以子序列的形式出现过，
那么给 sub 不断地添加字符，它也不会出现。而 str[i] 就是 sub 添加
若干个（可以为零个）字符得到的结果。

*/

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int ans = -1;
        // 枚举每一个字符串，假设把当前这个字符串当作特殊字符串
        for (int i = 0; i < strs.size(); ++i) {
            bool check = true;// 假设当前字符串是特殊字符串，标志号
            for (int j = 0; j < strs.size(); ++j) {
                if (i != j && subseq(strs[i], strs[j])) {
                    check = false;// 满足if条件则说明当前字符串不是特殊字符串
                    break;
                }
            }
            if (check) ans = max(ans, (int)strs[i].size());
        }
        return ans;
    }
    bool subseq(string& sub, string& org) {
        int pts = 0, pto = 0;
        while (pts < sub.size() && pto < org.size()) {
            if (sub[pts] == org[pto]) ++pts;
            ++pto;
        }
        return pts == sub.size();
    }
};
// O(n^2 * l) n是strs的长度，l是字符串的平均长度
// O(1)

// 官解的判断子串的函数做成了lambda表达式，放在了主函数里面
auto is_subseq = [](const string& s, const string& t) -> bool {
    // 尾置返回类型，auto类型推导
    int pt_s = 0, pt_t = 0;
    while (pt_s < s.size() && pt_t < t.size()) {
        if (s[pt_s] == t[pt_t]) ++pt_s;
        ++pt_t;
    }
    return pt_s == s.size();
}