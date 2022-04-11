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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = root;
        while (1){
            if (node->val < p->val && node->val < q->val)
                node = node->right;
            else if (node->val > p->val && node->val > q->val)
                node = node->left;
            else break;
        }
        return node;
    }
};
//O(n) O(1)