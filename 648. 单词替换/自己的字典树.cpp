struct trie {
    vector<trie*> t;
    bool end;

    trie() : t(26), end(false) {}
    void insert(string s) {
        trie* node = this;
        for (char c : s) {
            c -= 'a';
            if (node->t[c] == nullptr) node->t[c] = new trie();
            node = node->t[c];
        }
        node->end = true;
    }
    int searchprefix(string s) {
        trie* node = this;
        int cnt = 0;
        for (char c : s) {
            c -= 'a';
            if (node->end) return cnt;
            if (node->t[c] == nullptr) return s.size();
            ++cnt;
            node = node->t[c];
        }
        return cnt;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        trie tr;
        string ans;
        for (const auto& d : dictionary) {
            tr.insert(d);
        }
        int p = 0, last = 0;
        while (p <= sentence.size()) {
            if (sentence[p] == ' ' || p == sentence.size()) {
                string sub = sentence.substr(last, p - last);
                int tmp = tr.searchprefix(sub);
                ans += sentence.substr(last, tmp);
                ans.append(1, ' ');
                last = p + 1;
            }
            ++p;
        }
        ans.pop_back();
        return ans;
    }
};