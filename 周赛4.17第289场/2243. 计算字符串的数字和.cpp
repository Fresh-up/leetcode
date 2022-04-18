// 自己写的代码
class Solution {
public:
    string digitSum(string s, int k) {
        if (s.size() <= k) return s;
        string ss;
        int row = s.size() / k;
        int tail = s.size() % k;
        int he = 0;
        for (int i = 0, j = 1; i < s.size() && row > 0; ++i, ++j){
            if (j == k){
                he += s[i] - '0';
                ss += to_string(he);
                j = 0;
                he = 0;
                --row;
            }
            else he += s[i] - '0';
        }
        if (tail > 0){
            he = 0;
            for (int i = s.size() - 1; tail > 0; --tail, --i){
                he += s[i] - '0';
            }
            ss += to_string(he);
        }
        return digitSum(ss, k);
    }
};

// 别人写的代码
class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k){
            string nxt;
            int sm = 0;
            for (int i = 0; i < s.size(); ++i){
                sm += s[i] - '0';
                if (i % k == k - 1 || i == s.size() - 1){
                    nxt += to_string(sm);
                    sm = 0;
                }
            }
            s = nxt;
        }
        return s;
    }
};
// 总结：遇到遍历内分组的题目用i % k == k - 1求余方法