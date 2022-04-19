class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) return;
        
        int n = nums.size();
        for (int i = n - 2; i >= 0; --i){
            if (nums[i] < nums[i + 1]){
                for (int j = i + 1; j <= nums.size(); ++j){
                    if (j == nums.size() || nums[j] <= nums[i]){
                        f(nums, i, j - 1);
                        sort(nums.begin() + i + 1, nums.end());
                        return;
                    }
                }
            }
        }
        sort(nums.begin(), nums.end());
        return;
    }
    void f(vector<int>& nums, int l, int r){
        while (r != l){
            swap(nums[r], nums[r-1]);
            --r;
        }
    }
};
// 最坏的情况是从尾到头遍历一次，然后从头到尾遍历一次O(2n)
// 但sort的复杂度一般为O(nlogn),所以总复杂度为O(nlogn)
// O(1)
// 下标为i的迭代器为nums.begin() + i