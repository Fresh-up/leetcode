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
    //思路：把根节点到p和q的路径都找出来，放在一个数组里，再比较路径
    bool flag = false;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> t1;
        vector<TreeNode*> t2;
        find(t1, root, p);
        flag = false;
        find(t2, root, q);
        int i = 0, j = 0;
        while (i < t1.size() && j < t2.size() && 
                t1[i]->val == t2[j]->val){
            ++i;
            ++j;
        }
        return t1[i-1];
    }
    void find(vector<TreeNode*>& t, TreeNode* root, TreeNode* node){
        if (!root || flag) return;
        //回溯
        if (root->val == node->val){
            t.emplace_back(root);
            flag = true;
            return;
        }
        t.emplace_back(root);
        find(t, root->left, node);
        find(t, root->right, node);
        if (flag == false)
            t.pop_back();
    }
};
//O(n) O(n)