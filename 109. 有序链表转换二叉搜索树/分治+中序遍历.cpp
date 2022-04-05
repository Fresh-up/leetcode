struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    int getlen(ListNode* head){
        int len = 0;
        for (;head; ++len, head = head->next);
        return len;
    }
    TreeNode* buildtree(ListNode*& head, int left, int right){
        if (left > right) return nullptr;
        int mid = (left + right + 1) / 2;
        TreeNode* root = new TreeNode();
        root->left = buildtree(head, left, mid - 1);//取的是head的引用，head的值改变了
        root->val = head->val;
        head = head->next;
        root->right = buildtree(head, mid + 1, right);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int n = getlen(head) - 1;
        return buildtree(head, 0, n);
    }
};