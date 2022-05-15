class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        string last = words[0];
        sort(last.begin(), last.end());
        int i = 1;
        string tmp;
        while (i < words.size()) {
            tmp = words[i];
            sort(tmp.begin(), tmp.end());
            if (tmp == last) {
                words.erase(words.begin() + i);
            } else {
                last = tmp;
                ++i;
            }
        }
        return words;
    }
};