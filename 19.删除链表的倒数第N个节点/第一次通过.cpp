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
//思路：倒数第N个，一定要找到链表最后一个元素，干脆把链表全部反转，
//删除后再反转回来
class Solution {
public:
    ListNode* reverse(ListNode* head){
        if (!head || !head->next) return head;
        //递归法
        ListNode* node = reverse(head->next);
        //(错误写法)node->next = head;原本这样写,愣是没转过来
        //node永远指向原链表最后一个节点，主要操作是下面两项
        head->next->next = head;
        head->next = nullptr;
        return node;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = reverse(head);
        ListNode* removed = node;
        
        if (n == 1){
            node = node->next;
            removed->next = nullptr;
            delete removed;
        }
        else {
            ListNode* preremoved;
            while (n != 1){
                preremoved = removed;
                removed = removed->next;
                --n;
            }
            preremoved->next = removed->next;
            removed->next = nullptr;
            delete removed;
        }
        return reverse(node);
    }
};
// 4ms 77.27%
// 10.3MB 94.41%