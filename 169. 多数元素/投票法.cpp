// cnt作为是否重新选举的依据，如果cnt < 0则重新选举；
// 最后一定是众数的cnt > 0
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = -1;
        int candidate = -1;
        for (const auto& num : nums){
            if (candidate == num){
                ++cnt;
            }
            else if (--cnt < 0){
                candidate = num;
                cnt = 1;
            }
        }
        return candidate;
    }
};
// O(n) O(1)
// 取自评论的解释:如果候选人不是maj 则 maj,会和其他非候选人一起反对 
// 会反对候选人,所以候选人一定会下台(maj==0时发生换届选举),
// 如果候选人是maj , 则maj 会支持自己，其他候选人会反对，同样因为maj 
// 票数超过一半，所以maj 一定会成功当选