class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int res = 0;
        unordered_set<string> myset;
        for (auto& email : emails) {
            int i = 0;
            string tmp;
            while (email[i] != '@' && email[i] != '+') {
                if (email[i] != '.') 
                    tmp.append(1, email[i]);
                ++i;
            }
            while (email[i] != '@') ++i;
            tmp += email.substr(i);
            if (!myset.count(tmp)) {
                myset.insert(tmp);
                ++res;
            }
        }
        return res;
    }
};