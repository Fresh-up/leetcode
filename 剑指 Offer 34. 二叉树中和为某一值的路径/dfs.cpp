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
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        vector<vector<int>> ans;
        vector<int> line;
        int sum = 0;
        backtrack(root, ans, target, line, sum);
        return ans;
    }
    void backtrack(TreeNode* root, vector<vector<int>>& ans, 
                    int target, vector<int>& line, int& sum){
        if (!root) return;
        if (!root->left && !root->right){//判断为叶子节点
            sum += root->val;
            line.emplace_back(root->val);
            if (sum == target)
                ans.emplace_back(line);
            sum -= root->val;
            line.pop_back();
            return;
        }
        sum += root->val;
        line.emplace_back(root->val);
        backtrack(root->left, ans, target, line, sum);
        backtrack(root->right, ans, target, line, sum);
        sum -= root->val;
        line.pop_back();
    }
};
//O(n) O(n)