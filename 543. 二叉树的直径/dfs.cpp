class Solution {
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        g(root);
        return ans;
    }
    int g(TreeNode* root) {
        if (root == nullptr) return 0;
        // 在求树的深度的同时，求直径
        int l = g(root->left);
        int r = g(root->right);
        ans = max(ans, l + r);
        return max(l, r) + 1;
    }
};
// O(n) O(height)