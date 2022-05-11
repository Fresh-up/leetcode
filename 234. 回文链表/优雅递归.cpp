class Solution {
    ListNode* front;
public:
    bool checkback(ListNode* head) {
        if (head != nullptr) {
            if (!checkback(head->next))// 一沉到底
                return false;
            if (head->val != front->val) {
                return false;
            }
            front = front->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        front = head;
        return checkback(head);
    }
};
// O(n) O(n)优雅递归