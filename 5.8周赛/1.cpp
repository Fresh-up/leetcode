class Solution {
public:
    string largestGoodInteger(string num) {
        char ch(' ');// char型必须这样初始化
        int cnt = 1;
        for (int i = 1; i < num.size(); ++i) {
            if (num[i] == num[i - 1]) {
                ++cnt;
            } else cnt = 1;
            if (cnt == 3) {
                if (ch < num[i]) ch = num[i];
            }
        }
        if (ch == ' ') return "";
        string s(3, ch);
        return s;
    }
};