/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool twotree(TreeNode* node1, TreeNode* node2){
        if (!node1 && !node2)
            return true;
        else if ((node1 && !node2) || (node2 && !node1) || (node1->val != node2->val)){
            return false;
        }
        else return twotree(node1->left, node2->right) && twotree(node1->right, node2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        return twotree(root->left, root->right);
    }
};
//4ms,71.98%
//16.1MB,11.25%