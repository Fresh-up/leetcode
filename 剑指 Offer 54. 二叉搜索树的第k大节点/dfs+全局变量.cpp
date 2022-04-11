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
    int ki, ans;
    int kthLargest(TreeNode* root, int k) {
        ki = k;
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root){
        if (!root || ki == 0) return;
        dfs(root->right);
        --ki;
        if (ki == 0){
            ans = root->val;
            return;
        }
        dfs(root->left);
    }
};
//用全局变量打败98%,不用打败20~30%,居然差这么多