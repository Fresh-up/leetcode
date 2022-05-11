class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* tmp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmp);
        return root;
    }
};
// O(n)每个节点都遍历一次;递归深度为树的深度，通常来讲是O(logn)
// 但是最坏情况是退化成链表，所以是O(n)