class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> ress;
        deque<TreeNode*> myque;
        myque.push_back(root);

        while(!myque.empty()){
            int n = myque.size();
            vector<int> res;
            for (int i = 0; i < n; ++i){
                TreeNode* node = myque.front();
                res.emplace_back(node->val);
                if (node->left != nullptr)
                    myque.push_back(node->left);
                if (node->right != nullptr)
                    myque.push_back(node->right);
                myque.pop_front();
            }
            ress.emplace_back(res);
        }
        return ress;
    }
};
// O(n) O(n)