// 自己做的，没做出来
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        summ(root);
        int cnt = 0;
        count(root, cnt);
        return cnt;
    }
    // 树节点求和
    int summ(TreeNode* root) {
        if (root != nullptr) {
            root->val += summ(root->left) + summ(root->right);
            return root->val;
        } else return 0;
    }
    int count(TreeNode* root, int &cnt) {
        if (root == nullptr) return 0;
        else {
            int tmp = 1 + count(root->left, cnt) + count(root->right, cnt);
            if (root->val / tmp == tmp) ++cnt;
            return tmp;
        }
    }
};

// 别人做的，简洁高效
class Solution {
    typedef pair<int, int> pii;
    int ans;
    pii dfs(TreeNode *node) {
        if (node == nullptr) return pii(0, 0);
        pii L = dfs(node->left), R = dfs(node->right);
        int cnt = L.first + R.first + 1, sm = L.second + R.second + node->val;
        if (sm / cnt == node->val) ans++;
        return pii(cnt, sm);
    }
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};