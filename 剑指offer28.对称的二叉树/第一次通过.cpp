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
        //node1和node2都为空，对称
        if (!node1 && !node2)
            return true;
        //node1和node2只有一个为空，或者两者值不等，非对称
        else if ((node1 && !node2) || (node2 && !node1) || (node1->val != node2->val)){
            return false;
        }
        //判断子树是否对称
        else return twotree(node1->left, node2->right) && twotree(node1->right, node2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        //没必要那么长的判断
        if (!root->left && !root->right)
            return true;
        else if ((root->left && !root->right) || (!root->left && root->right)) 
            return false;
        else {
            if (root->left->val == root->right->val)
                return twotree(root->left, root->right);
            else return false;
        }
    }
};
// 执行用时：8 ms, 在所有 C++ 提交中击败了29.10%的用户
// 内存消耗：15.8 MB, 在所有 C++ 提交中击败了91.09%的用户
// 通过测试用例：195 / 195