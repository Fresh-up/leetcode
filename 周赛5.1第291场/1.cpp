// 思路：遍历字符串，如果当前字符是指定的字符，如果下一个字符>指定字符，
// 直接返回去掉该字符的字符串;如果下一个字符是指定字符，用另一个指针记录，
// 防止之后的字符都没有指定字符，如果是这样，应该返回去掉该字符的字符串

class Solution {
public:
    string removeDigit(string number, char digit) {
        int p = 0;
        int pp = 0;
        int n = number.size();

        while (p < n){
            if (number[p] == digit) {
                if (p < n - 1){
                    if (number[p + 1] > digit) {
                        return number.substr(0, p) + number.substr(p + 1, n);
                    }
                    else if (number[p + 1] == digit){
                        pp = p + 1;
                    }
                }
                pp = p;
            }
            ++p;
        }
        return number.substr(0, pp) + number.substr(pp + 1, n);
    }
};
// O(n) O(1)