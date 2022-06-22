// 基础的BFS
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ret;
        while (!q.empty()) {
            auto node = q.front();
            ret = node->val;
            if (node->right) q.push(node->right);
            if (node->left) q.push(node->left);
            q.pop();
        }
        return ret;
    }
};
// O(n) O(n)

// 自己写的版本
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        // 层序遍历
        queue<TreeNode*> q;
        q.push(root);
        int n = 1;
        int ret;
        while (!q.empty()) {
            int cnt = 0;
            ret = q.front()->val;
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                if (node->left) {
                    q.push(node->left);
                    ++cnt;
                }
                if (node->right) {
                    q.push(node->right);
                    ++cnt;
                }
                q.pop();
            }
            n = cnt;
        }
        return ret;
    }
};