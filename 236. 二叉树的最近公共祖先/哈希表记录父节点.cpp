class Solution {
public:
    unordered_map<int, TreeNode*> father;
    unordered_map<int, bool> vis;
    void dfs(TreeNode* root) {
        if (root->left != nullptr){
            father[root->left->val] = root;
            dfs(root->left);
        }
        if (root->right != nullptr){
            father[root->right->val] = root;
            dfs(root->right);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        father[root->val] = nullptr;
        dfs(root);
        while (p != nullptr){
            vis[p->val] = true;
            p = father[p->val];
        }
        while (q != nullptr){
            if (vis[q->val]) return q;
            q = father[q->val];
        }
        return nullptr;
    }
};
// O(n) O(n)