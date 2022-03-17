//看了标准答案，精简了一下，
class Solution {
public:
    bool twotree(TreeNode* node1, TreeNode* node2){
        if (!node1 && !node2)
            return true;
        else if (!node2 || !node1 || (node1->val != node2->val)){
            return false;
        }
        else return twotree(node1->left, node2->right) && twotree(node1->right, node2->left);
    }

    bool isSymmetric(TreeNode* root) {
        return !root ? true : twotree(root->left, root->right);
    }
};

//相同的代码提交了两次，一次12ms，一次4ms
//改了一下第一个else if条件，改成原来那样else if ((node1 && !node2) || (node2 && !node1) || (node1->val != node2->val))
//0ms
//结论：应该效率都相差不大，测试的对象有随机性，造成每次的效率不同