class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 4) return ans;// 小于4,不是小于3
        sort(nums.begin(), nums.end());//记得排序
        for (int a = 0; a < n - 3; ++a){
            if (a > 0 && nums[a] == nums[a-1]) 
                continue;
            // 最好加强制类型转换
            if ((long) nums[a] + nums[a+1] + nums[a+2] + nums[a+3] > target)
                break;
            if ((long) nums[a] + nums[n-1] + nums[n-2] + nums[n-3] < target)
                continue;
            
            for (int b = a + 1; b < n - 2; ++b){
                if (b > a + 1 && nums[b] == nums[b - 1])
                    continue;
                if ((long) nums[a] + nums[b] + nums[b+1] + nums[b+2] > target)
                    break;
                if ((long) nums[a] + nums[b] + nums[n-1] + nums[n-2] < target)
                    continue;
                
                int c = b + 1, d = n - 1;
                while (c < d){
                    int temp = nums[a] + nums[b] + nums[c] + nums[d];
                    if (temp == target){
                        // 这里有个vector<int>
                        ans.emplace_back(vector<int>{nums[a], nums[b], nums[c], nums[d]});
                        // 记得是个循环
                        while (c < d && nums[c] == nums[c+1])
                            ++c;
                        ++c;// 还是相同元素，还要加
                        while (c < d && nums[d] == nums[d-1])
                            --d;
                        --d;// 还是相同元素，还要减
                    }
                    else if (temp < target)
                        ++c;
                    else --d;
                }
            }
        }
        return ans;
    }
};