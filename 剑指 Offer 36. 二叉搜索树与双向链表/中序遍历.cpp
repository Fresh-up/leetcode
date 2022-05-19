// 一般拿到树的题目就应该判断用什么序遍历，熟练掌握三种遍历方式
// 搜索树的性质：中序遍历是递增序列
// 前驱节点最好放在函数外部定义作为全局函数
class Solution {
public:
    Node* head = nullptr, *pre = nullptr;
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }
    void dfs(Node* root) {
        if (root == nullptr) return;
        dfs(root->left);
        if (pre == nullptr) {
            head = root;
            pre = root;
        }
        else {
            pre->right = root;
            root->left = pre;
            pre = root;
        }
        dfs(root->right);
    }
};
// O(n)中序遍历需要访问所有节点
// O(n)最差情况下，搜索树退化为链表，递归深度为N，使用O(N)的栈空间