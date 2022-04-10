struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        dfs(ans, root);
        return ans;
    }
    void dfs(vector<int>& ans, TreeNode* root){
        if (!root){
            return;
        }
        dfs(ans, root->left);
        ans.emplace_back(root->val);
        dfs(ans, root->right);
    }
};
//O(n) O(n)