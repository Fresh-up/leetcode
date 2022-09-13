class Solution {
public:
    string smallestNumber(string pattern) {
        string s;
        int ni = 0, nd = 0, i = 0, since = 1;
        pattern = 'I' + pattern;
        while (i <= pattern.size()) {
            if (i == 0) ++ni;
            else if (i == pattern.size() || pattern[i] != pattern[i-1]) {
                if (pattern[i] == 'D') ++nd;
                else {
                    while (ni != 1) {
                        s += to_string(since);
                        ++since;
                        --ni;
                    }
                    s += to_string(since + nd);
                    --since;
                    while (nd != 0) {
                        s += to_string(since + nd);
                        --nd;
                    }
                    ni = 1;
                    since = i + 1;
                }
            }else {
                if (pattern[i] == 'I') ++ni;
                else ++nd;
            } 
            ++i;
        }
        return s;
    }
};