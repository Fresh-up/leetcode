class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        if (preorder.size() == 1) return root;
        vector<int> leftin;
        int pre = 0, in = 0, cnt = 0;
        int n = preorder.size();
        while (in < n){
            if (inorder[in] != preorder[pre]){
                leftin.emplace_back(inorder[in]);
                ++cnt;
                break;
            }
            ++in;
        }
        pre += cnt;
        vector<int> rightin(inorder.begin() + in + 1, inorder.end());
        vector<int> leftpre(preorder.begin() + 1, preorder.begin() + pre + 1);
        vector<int> rightpre(preorder.begin() + 1 + pre, preorder.end());
        root->left = buildTree(leftpre, leftin);
        root->right = buildTree(rightpre, rightin);
        return root;
    }
};
// 自己的方法很慢