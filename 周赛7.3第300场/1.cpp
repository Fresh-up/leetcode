class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mp;
        int i = 0;
        for (const char& k : key) {
            if (k == ' ') continue;
            if (!mp.count(k)) {
                mp[k] = 'a' + i;
                ++i;
            }
        }
        for (char& m : message) {
            if (m == ' ') continue;
            m = mp[m];
        }
        return message;
    }
};