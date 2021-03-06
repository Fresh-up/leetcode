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
//虽然逻辑有点复杂，但是能ac感觉良好
/*
思路：对我来说，难点主要在有进位的情况下，只有单个链表有元素和两个链表都没元素
的时候应该怎么办，于是我又创建了个函数专门处理一个链表和进位的相加。
if太多，逻辑很混乱
*/
class Solution {
public:
    int flag = 0;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2 && !flag) return nullptr;
        if (!l1 && !l2 && flag){
            ListNode* ni = new ListNode(1);
            return ni;
        }
        if (!l1 && l2) return addOne(l2);
        if (l1 && !l2) return addOne(l1);
        int sum = l1->val + l2->val + flag;
        ListNode* node = new ListNode(0);
        if (sum >= 10){
            node->val = sum % 10;
            flag = 1;
        }
        else {
            node->val = sum;
            flag = 0;
        }
        node->next = addTwoNumbers(l1->next, l2->next);
        return node;
    }
    ListNode* addOne(ListNode* l){
        if (!l && !flag) return nullptr;
        if (!l && flag){
            ListNode* n = new ListNode(1);
            return n;
        }
        int sum = l->val + flag;
        ListNode* node = new ListNode(0);
        if (sum == 10){
            node->val = 0;
            flag = 1;
        }
        else {
            node->val = sum;
            flag = 0;
        }
        node->next = addOne(l->next);
        return node;
    }
};