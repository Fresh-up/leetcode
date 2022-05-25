class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> res;
        bool ltor = true;
        deque<TreeNode*> q;
        q.push_back(root);
        while (!q.empty()) {
            int len = q.size();
            vector<int> tmp;
            if (ltor) {
                for (int i = 0; i < len; ++i) {
                    TreeNode* node = q.front();
                    tmp.emplace_back(node->val);
                    q.pop_front();
                    if (node->left != nullptr) q.push_back(node->left);
                    if (node->right != nullptr) q.push_back(node->right);
                }
            } else {
                for (int i = 0; i < len; ++i) {
                    TreeNode* node = q.back();
                    tmp.emplace_back(node->val);
                    q.pop_back();
                    if (node->right != nullptr) q.push_front(node->right);
                    if (node->left != nullptr) q.push_front(node->left);
                }
            }
            ltor = !ltor;
            res.emplace_back(tmp);
        }
        return res;
    }
};
// O(n) O(n)最差情况是满二叉树，最多有n/2的节点在队列中