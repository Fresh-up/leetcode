class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set visited;
        while (head){
            if (visited.count(head)) return true;
            else visited.insert(head);
            head = head->next;
        }
        return false;
    }
};