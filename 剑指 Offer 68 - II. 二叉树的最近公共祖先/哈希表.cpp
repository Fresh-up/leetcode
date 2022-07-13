class Solution {
public:
    unordered_map<int, TreeNode*> mp;
    unordered_map<int, bool> vis;
    void dfs(TreeNode* root) {
        if (root->left) {
            mp[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right) {
            mp[root->right->val] = root;
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        mp[root->val] = nullptr;
        dfs(root);
        while (p != nullptr) {
            vis[p->val] = true;
            p = mp[p->val];
        }
        while (q != nullptr) {
            if (vis[q->val]) return q;
            q = mp[q->val];
        }
        return nullptr;
    }
};