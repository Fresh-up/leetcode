// 异或 a⊕0 = a     a⊕a = 0
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (const auto& i : nums) ret ^= i;
        return ret;
    }
};
// O(n) O(1)