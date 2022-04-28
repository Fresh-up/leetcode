class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int odd = 0, even = nums.size() - 1;
        while (odd < even){
            if ((nums[odd] & 1) && !(nums[even] & 1))
                swap(nums[odd], nums[even]);
            if (!(nums[odd] & 1)) ++odd;
            if (nums[even] & 1) --even;
        }
        return nums;
    }
};
// O(n) O(1)