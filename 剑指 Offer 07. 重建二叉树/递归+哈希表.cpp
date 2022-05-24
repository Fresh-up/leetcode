class Solution {
    unordered_map<int, int> mymap;
public:
    TreeNode* build(const vector<int>& preorder, const vector<int>& inorder, int prel, int prer, int inl, int inr) {
        if (prel > prer) return nullptr;
        // 前序遍历第一个节点就是根节点
        int preindex_root = prel;
        // 创建根节点
        TreeNode* root = new TreeNode(preorder[prel]);
        // 用哈希表得到根节点在中序遍历中的下标
        int inindex_root = mymap[preorder[prel]];
        // 得到左子树的节点数
        int leftnum = inindex_root - inl;
        // 递归创建左右子树
        root->left = build(preorder, inorder, prel + 1, prel + leftnum, inl, inindex_root - 1);
        root->right = build(preorder, inorder, prel + leftnum + 1, prer, inindex_root + 1, inr);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // 把中序遍历的值和下标塞入哈希表中,方便找出根节点的值和左右子树的长度
        for (int i = 0; i < inorder.size(); ++i) mymap[inorder[i]] = i;
        return build(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};