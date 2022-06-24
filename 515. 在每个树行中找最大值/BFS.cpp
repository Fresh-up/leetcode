class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        int cnt = 1;
        while(!q.empty()) {
            int m = q.front()->val;
            int k = 0;
            while (cnt > 0) {
                TreeNode* node = q.front();
                m = max(m, node->val);
                q.pop();
                if (node->left) {
                    q.push(node->left);
                    ++k;
                }
                if (node->right) {
                    q.push(node->right);
                    ++k;
                }
                --cnt;
            }
            cnt = k;
            res.emplace_back(m);
        }
        return res;
    }
};
// O(n) O(n)