struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* node = nullptr;
        while (head){
            node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = node;
        }
        return prev;
    }
};
//O(n) O(1)