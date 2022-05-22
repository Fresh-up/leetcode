class Solution {
public:
    int percentageLetter(string s, char letter) {
        double i = 0;
        double j;
        for (const char& ss : s) {
            if (ss == letter) ++i;
        }
        j = i / s.size();
        i = j * 100;
        return i;
    }
};

// 不用double的做法
class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt = 0;
        for (const char& c : s) if (c == letter) ++cnt;
        return cnt * 100 / (int)s.size();// 想除出来是百分数，就先×100再除
    }
};