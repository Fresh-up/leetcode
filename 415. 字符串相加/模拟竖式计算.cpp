class Solution {
public:
    string addStrings(string num1, string num2) {
        int p1 = num1.size() - 1, p2 = num2.size() - 1;
        int c = 0;
        string res;
        while (p1 >= 0 || p2 >= 0 || c != 0) {
            int x = p1 >= 0 ? num1[p1--] - '0' : 0;
            int y = p2 >= 0 ? num2[p2--] - '0' : 0;
            int tmp = x + y + c;
            res.push_back('0' + tmp % 10);
            c = tmp / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// O(n+m) O(n)