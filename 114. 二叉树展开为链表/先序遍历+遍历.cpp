class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        vector<TreeNode*> tmp;
        dfs(root, tmp);
        int i = 1;
        int n = tmp.size();
        while (root != nullptr && i < n){
            root->left = nullptr;
            root->right = tmp[i];
            root = tmp[i];
            ++i;
        }
    }
    void dfs(TreeNode* root, vector<TreeNode*> &tmp){
        if (root == nullptr) return;
        tmp.emplace_back(root);
        dfs(root->left, tmp);
        dfs(root->right, tmp);
    }
};
// O(n) O(n)