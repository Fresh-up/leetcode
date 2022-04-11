#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        //唯一且致命的毛病在于你把根节点特殊化了
        return abs(depth(root->left) - depth(root->right)) < 2 && 
                isBalanced(root->left) && isBalanced(root->right);
    }
    //先求一棵树的深度
    int depth(TreeNode* root){
        if (!root) return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
};//O(nxn) O(n)


//以下是错误示范
// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         if (!root) return true;
//         //唯一且致命的毛病在于你把根节点特殊化了
//         return dfs(root->left) && dfs(root->right);
//     }
//     bool dfs(TreeNode* root){
//         if (!root) return true;
        
//         return abs(depth(root->left) - depth(root->right)) < 2;
//     }
//     //先求一棵树的深度
//     int depth(TreeNode* root){
//         if (!root) return 0;
//         return 1 + max(depth(root->left), depth(root->right));
//     }
// };