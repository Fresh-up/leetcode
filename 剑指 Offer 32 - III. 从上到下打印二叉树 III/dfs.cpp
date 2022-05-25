class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        func(root, 0);
        return res;
    }
    void func(TreeNode* root, int i) {
        // 根节点是第0层
        // i的作用有三个：1.表示第i层  2.表示从左向右还是从右向左
        // 3.在数组中查找第几层的数组
        if (root != nullptr) {
            if (res.size() <= i) {
                // 每下一层，新的一层则创建一个空数组
                res.emplace_back(vector<int> ());
            }
            if (i & 1) {// 奇数层，从右向左插入
                res[i].insert(res[i].begin(), root->val);
            } else res[i].push_back(root->val);// 偶数层，从左向右插入
            func(root->left, i + 1);
            func(root->right, i + 1);
        }
    }
};
// vector插入删除操作的时间复杂度是O(n)要执行大概n/2次
// 这种方法虽然简洁，但是还是挺慢的