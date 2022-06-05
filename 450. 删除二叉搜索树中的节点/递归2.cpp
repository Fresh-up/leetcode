class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
            return root;
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        } else {
            if (!root->left && !root->right) return nullptr;
            else if (!root->left) return root->right;
            else if (!root->right) return root->left;
            else {
                TreeNode* node = root->right;
                while (node->left) node = node->left;
                root->right = deleteNode(root->right, node->val);
                node->left = root->left;
                node->right = root->right;
                return node;
            }
        }
        return root;
    }
};