class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelnum = q.size();// 该层有多少个节点
            res.emplace_back(vector<int>());// 推入一个空数组
            for (int i = 0; i < levelnum; ++i) {
                // 遍历一层的所有节点，顺便把子节点按序推入队列
                auto node = q.front();
                q.pop();
                res.back().emplace_back(node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
        }
        return res;
    }
};
// BFS层序遍历，用队列
// O(n) O(n)