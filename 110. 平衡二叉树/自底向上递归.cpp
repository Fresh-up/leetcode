// 类似后序遍历

class Solution {
public:
    int height(TreeNode* root){
        if (!root) return 0;
        int leftheight = height(root->left);
        int rightheight = height(root->right);
        if (leftheight == -1 || rightheight == -1 || abs(leftheight - rightheight) > 1)
            return -1;
        else return max(leftheight, rightheight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};

// 时间复杂度：O(n)O(n)，其中 nn 是二叉树中的节点个数。使用自底向上的递归，
// 每个节点的计算高度和判断是否平衡都只需要处理一次，最坏情况下需要遍历二叉树中的所有节点，
// 因此时间复杂度是 O(n)O(n)。
// 空间复杂度：O(n)O(n)，其中 nn 是二叉树中的节点个数。
// 空间复杂度主要取决于递归调用的层数，递归调用的层数不会超过 nn。
