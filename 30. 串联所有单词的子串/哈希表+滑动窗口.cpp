class Solution {
public:
    vector<int> findSubstring(string &s, vector<string> &words) {
        vector<int> res;
        int m = words.size(), n = words[0].size(), ls = s.size();
        for (int i = 0; i < n && i + m * n <= ls; ++i) {
            // 理解为一长串切段，每段n个字符长，两端不够长则舍去，便于窗口移动
            unordered_map<string, int> differ;
            for (int j = 0; j < m; ++j) {
                ++differ[s.substr(i + j * n, n)];
            }
            for (const auto& word : words) {
                if (--differ[word] == 0) differ.erase(word);
            }
            for (int start = i; start < ls - m * n + 1; start += n) {
                // 有可能s很长，需要窗口移动，窗口长度是m*n, 每次移动一个单词的长度，即n
                // 直到s的末尾
                if (start != i) {
                    string word = s.substr(start + (m - 1) * n, n);
                    if (++differ[word] == 0) differ.erase(word);
                    word = s.substr(start - n, n);
                    if (--differ[word] == 0) differ.erase(word);
                }
                if (differ.empty()) res.emplace_back(start);
            }
        }
        return res;
    }
};