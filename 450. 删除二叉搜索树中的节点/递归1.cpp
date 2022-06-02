class Solution {
public:
    TreeNode* dummy = new TreeNode();
    bool isleft = true;
    TreeNode* cur;
    TreeNode* pre = dummy;
    TreeNode* deleteNode(TreeNode* root, int key) {
        dummy->left = root;
        cur = root;
        if (findnode(root, key) == false) return dummy->left;
        if (cur->right == nullptr) {
            if (isleft) pre->left = cur->left;
            else pre->right = cur->left;
            delete cur;
            return dummy->left;
        }
        TreeNode* lft = cur->right;
        while (lft->left != nullptr) lft = lft->left;
        lft->left = cur->left;
        if (isleft) pre->left = cur->right;
        else pre->right = cur->right;
        delete cur;
        return dummy->left;
    }
    bool findnode(TreeNode* root, int key) {
        if (root == nullptr) return false;
        if (root->val > key) {
            isleft = true;
            pre = root;
            cur = root->left;
            return findnode(root->left, key);
        } else if (root->val < key) {
            isleft = false;
            pre = root;
            cur = root->right;
            return findnode(root->right, key);
        } else return true;
    }
};