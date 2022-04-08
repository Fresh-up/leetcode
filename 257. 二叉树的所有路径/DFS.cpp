#include <vector>
#include <string>
using namespace std;

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string str;
        dfs(root, str, ans);
        return ans;
    }
    void dfs(TreeNode* root, string str, vector<string>& ans){//参数的str不可引用
        if (root){//节点不为空
            str += to_string(root->val);
            if (!root->left && !root->right){
                ans.emplace_back(str);
            }
            else {
                str += "->";
                dfs(root->left, str, ans);
                dfs(root->right, str, ans);
            }
        }
        //节点为空，直接忽略
    }
};