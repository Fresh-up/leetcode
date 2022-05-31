class Solution {
public:
    string compressString(string S) {
        string s;
        if (S.size() == 0) return "";
        char c = S[0];
        int cnt = 1;
        for (int i = 1; i < S.size(); ++i) {
            if (S[i] == c) {
                cnt++;
                continue;
            }
            s.append(1, c);
            s += to_string(cnt);
            c = S[i];
            cnt = 1;
        }
        s.append(1, c);
        s += to_string(cnt);
        if (s.size() < S.size())
            return s;
        else return S;
    }
};