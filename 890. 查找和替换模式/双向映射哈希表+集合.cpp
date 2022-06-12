class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> vec;
        for (const auto& word : words) {
            if (word.size() != pattern.size()) continue;
            unordered_map<char, char> mymap;
            unordered_set<char> myset;
            bool flag = false;
            for (int i = 0; i < pattern.size(); ++i) {
                if (!mymap.count(pattern[i])) {
                    if (!myset.count(word[i])) {
                        mymap[pattern[i]] = word[i];
                        myset.insert(word[i]);
                    } else {
                        flag = true;
                        break;
                    }
                } else if (mymap[pattern[i]] != word[i]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) vec.emplace_back(word);
        }
        return vec;
    }
};