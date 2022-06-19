class Solution {
public:
    unordered_map<int, int> mymap;
    int maxval;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        maxval = INT_MIN;
        ssum(root);
        auto it = mymap.begin();
        vector<int> vec;
        while (it != mymap.end()) {
            if (it->second == maxval) {
                vec.emplace_back(it->first);
            }
            ++it;
        }
        return vec;
    }
    int ssum(TreeNode* node) {
        if (node == nullptr) return 0;
        int lsum = ssum(node->left);
        int rsum = ssum(node->right);
        int s = node->val + lsum + rsum;
        ++mymap[s];
        maxval = max(mymap[s], maxval);
        return s;
    }
};
// O(n) O(n)

// 官解更简洁，思路一样的
class Solution {
public:
    unordered_map<int, int> mymap;
    int maxval = 0;

    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        int s = node->val + dfs(node->left) + dfs(node->right);
        maxval = max(maxval, ++mymap[s]);
        return s;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> vec;
        for (auto &[s, c] : mymap) {
            if (c == maxval) {
                vec.emplace_back(s);
            }
        }
        return vec;
    }
};