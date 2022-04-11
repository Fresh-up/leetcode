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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> t1;
        vector<TreeNode*> t2;
        find(t1, root, p);
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
        if (!root) return;
        t.emplace_back(root);
        if (root->val > node->val)
            find(t, root->left, node);
        else if (root->val == node->val)
            return;
        else find(t, root->right, node);
    }
};
//O(n) O(n)