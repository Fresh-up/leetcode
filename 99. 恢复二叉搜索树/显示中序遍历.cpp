class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        pair<int, int> swapped = findtwo(nums);
        recover(root, 2, swapped.first, swapped.second);
    }
    void inorder(TreeNode* root, vector<int>& nums){
        if (!root) return;

        inorder(root->left, nums);
        nums.emplace_back(root->val);
        inorder(root->right, nums);
    }

    pair<int, int> findtwo(vector<int>& nums){
        int n = nums.size();
        int idx1 = -1, idx2 = -1;
        for (int i = 0; i < n - 1; ++i){
            if (nums[i+1] < nums[i]){
                idx2 = i + 1;
                if (idx1 == -1) idx1 = i;
                else break;
            }
        }
        return {nums[idx1], nums[idx2]};
    }

    void recover(TreeNode* r, int count, int x, int y){
        if (r){
            if (r->val == x || r->val == y){
                r->val = r->val == x ? y : x;
                if (--count == 0) return;
            }
            recover(r->left, count, x, y);
            recover(r->right, count, x, y);
        }
        
    }
};

// O(n)  O(n)