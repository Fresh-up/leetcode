class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == nullptr) {
            Node* creat = new Node(insertVal);
            creat->next = creat;
            return creat;
        }
        Node* fast = head->next, *slow = head;
        while (fast != head) {
            if (fast->val >= insertVal && slow->val <= insertVal) {
                break;
            } else if (fast->val < slow->val && (fast->val > insertVal || slow->val < insertVal)) break;
            slow = fast;
            fast = fast->next;
        }
        Node* node = new Node(insertVal, fast);
        slow->next = node;
        return head;
    }
};
// O(n) O(1)