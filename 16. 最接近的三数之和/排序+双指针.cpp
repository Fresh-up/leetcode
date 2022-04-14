class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), temp, ans;
        int mindiff = 100000000;
        for (int i = 0; i < n; ++i){
            for (int j = i + 1, k = n - 1; j < k;){
                temp = nums[i] + nums[j] + nums[k];
                if (abs(temp - target) < mindiff){
                    mindiff = abs(temp - target);
                    ans = temp;
                }
                if (temp > target) --k;
                else if (temp < target) ++j;
                else return ans;
            }
        }
        return ans;
    }
};
//O(nxn) O(n)