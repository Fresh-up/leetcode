#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stack;
        long inorder = LONG_MIN;

        while (!stack.empty() || root){
            while (root){
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            //如果中序遍历得到的节点值小于等于前一个inorder,说明不是二叉搜索树
            if (root->val <= inorder) return false;
            inorder = root->val;
            root = root->right;
        }
        return true;
    }
};
//O(n) O(n)