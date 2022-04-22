class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
    TreeNode* build(vector<int>& nums, int l, int r){
        if (l <= r){
            int mid = (l + r) / 2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = build(nums, l, mid - 1);
            root->right = build(nums, mid + 1, r);
            return root;
        }
        return nullptr;
    }
};
// O(n)
// O(logn) 空间复杂度不考虑返回值，所以只与栈的深度有关，logn