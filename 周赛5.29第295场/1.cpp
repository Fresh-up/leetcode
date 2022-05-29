class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> t;
        unordered_map<char, int> sc;
        int res = INT_MAX;
        for (const char& c : target) ++t[c];
        for (const char& c : s) {
            if (!t.count(c)) continue;
            ++sc[c];
        }
        auto it = t.begin();
        while (it != t.end()) {
            res = min(res, sc[it->first] / it->second);
            ++it;
        }
        return res;
    }
};