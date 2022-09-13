// 难点在于如何描述一棵树，用序列化的方式
// 根节点(左子树)(右子树)
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, TreeNode*> mp;
        unordered_set<TreeNode*> st;
        function<string(TreeNode*)> dfs = [&](TreeNode* r) -> string {
            if (!r) return "";
            string a = to_string(r->val) + "(" + dfs(r->left) + ")(" + dfs(r->right) + ")";
            if (mp.count(a)) st.insert(mp[a]);
            else mp[a] = r;
            return a;
        };
        dfs(root);
        return vector<TreeNode*> {st.begin(), st.end()};
        // OR return {st.begin(), st.end()};
    }
};