class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> mymap;
        for (int i = 0; i < messages.size(); ++i) {
            int k = 1;
            for (const char& s : messages[i]) if (s == ' ') ++k;
            mymap[senders[i]] += k;
        }
        string res;
        int k = 0;
        auto it = mymap.begin();
        while (it != mymap.end()) {
            if (it->second > k) {
                res = it->first;
                k = it->second;
            } else if (it->second == k) {
                res = res > it->first ? res : it->first;
            }
            ++it;
        }
        return res;
    }
};