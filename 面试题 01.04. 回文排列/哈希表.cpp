class Solution {
public:
    bool canPermutePalindrome(string s) {
        bool odd = false;
        unodered_map<char, int> mymap;
        for (const char& c : s) {
            ++mymap[c];
        }
        auto it = mymap.begin();
        while (it != mymap.end()) {
            if (it->second & 1) {
                if (odd) return false;
                else odd = true;
            }
        }
        return true;
    }
};