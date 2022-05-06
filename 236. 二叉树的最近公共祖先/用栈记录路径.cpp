class Solution {
public:
    // 返回bool很有必要
    bool findpath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path) {
        if (root == nullptr) return false;
        path.push(root);
        if (root == x) return true;// 找到返回true, 不再往下递归
        if(findpath(root->left, x, path)) return true;
        if(findpath(root->right, x, path)) return true;
        path.pop();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pathp, pathq;
        findpath(root, p, pathp);
        findpath(root, q, pathq);
        
        while (pathp.size() != pathq.size()){
            if (pathp.size() > pathq.size()){
                pathp.pop();
            }
            else pathq.pop();
        }
        while (pathp.top() != pathq.top()){
            pathp.pop();
            pathq.pop();
        }
        return pathp.top();
    }
};
// O(n) O(n)