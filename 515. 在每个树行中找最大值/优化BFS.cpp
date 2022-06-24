class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        while(!q.empty()) {
            int len = q.size();
            int m = q.front()->val;
            while (len > 0) {
                TreeNode* node = q.front();
                m = max(m, node->val);
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                --len;
            }
            res.emplace_back(m);
        }
        return res;
    }
};
// O(n) O(n)