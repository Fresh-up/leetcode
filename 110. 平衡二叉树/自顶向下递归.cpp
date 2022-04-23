class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if (abs(hght(root->left) - hght(root->right)) < 2){
            return isBalanced(root->left) && isBalanced(root->right);
        }
        return false;
    }
    int hght(TreeNode* root){
        if (!root) return 0;
        return max(hght(root->left), hght(root->right)) + 1;
    }
};
// O(nxn) O(n)