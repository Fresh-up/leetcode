class Solution {
public:
    unordered_map<Node*, Node*> mymap;
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        if (!mymap.count(head)) {
            Node* newhead = new Node(head->val);
            mymap[head] = newhead;
            newhead->next = copyRandomList(head->next);
            newhead->random = copyRandomList(head->random);
        }
        return mymap[head];
    }
};
// O(n) O(n)