class Solution {
public:
    int strToInt(string str) {
        bool ispos = true;
        int res = 0, i = 0, bndry = INT_MAX / 10;
        while (i < str.size() && str[i] == ' ') ++i;
        if (i < str.size()) {
            if (str[i] == '+') ispos = true, ++i;
            else if (str[i] == '-') ispos = false, ++i;
            else if (isdigit(str[i]) == 0) return 0;
        }
        for (; i < str.size(); ++i) {
            if (res > bndry || res == bndry && str[i] > '7') 
                return ispos ? INT_MAX : INT_MIN;
            else if (isdigit(str[i]) == 1) 
                res = res * 10 + str[i] - '0';
            else break;
        }
        return ispos ? res : -res;
    }
};