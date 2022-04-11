#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        int ans;
        dfs(root, k, ans);
        return ans;
    }
    void dfs(TreeNode* root, int& k, int &ans){
        if (!root || k == 0) return;
        dfs(root->right, k, ans);
        --k;
        if (k == 0){
            ans = root->val;
            return;
        }
        dfs(root->left, k, ans);
    }
};
//O(logn) O(n)