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
    //快慢指针
    ListNode* getmid(ListNode* left, ListNode* right){
        ListNode* fast = left;
        ListNode* slow = left;
        while (fast != right && fast->next != right){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    TreeNode* buildtree(ListNode* left, ListNode* right){
        if (left == right) return nullptr;
        ListNode* mid = getmid(left, right);
        TreeNode* root = new TreeNode(mid->val);
        root->left = buildtree(left, mid);
        root->right = buildtree(mid->next, right);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        // ListNode* newhead = head;
        // while(head->next){
        //     head = head->next;
        // }
        //return buildtree(newhead, head);
        return buildtree(head, nullptr);
    }
};
//O(nlogn)  O(logn)