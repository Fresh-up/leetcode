/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* node = dummy;
        head = dummy;
        while (head->next){
            if (head->next->val >= x){
                node = head;
                break;
            }
            head = head->next;
        }
        while (head->next){
            if(head->next->val < x){
                ListNode* tmp = node->next;
                node->next = head->next;
                head->next = head->next->next;
                node->next->next = tmp;
                node = node->next;
            }
            else {
                head = head->next;
            }
        }
        node = dummy->next;
        delete dummy;
        return node;
    }
};//O(n) O(2)