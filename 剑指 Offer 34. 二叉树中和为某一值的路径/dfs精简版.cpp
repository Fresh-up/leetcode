#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

//去除sum,用target减去节点值，判断最后target是否为零即可
//为了减少dfs的参数，可以设置全局变量
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> line;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        backtrack(root, target);
        return ans;
    }
    void backtrack(TreeNode* root, int target){
        if (!root) return;
        target -= root->val;
        line.emplace_back(root->val);
        if (!root->left && !root->right && target == 0){//判断为叶子节点
            ans.emplace_back(line);
        }
        backtrack(root->left, target);
        backtrack(root->right, target);
        target += root->val;
        line.pop_back();
    }
};
//O(n) O(n)