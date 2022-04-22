class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> myset;
        for (const auto& i : nums){
            if (!myset.count(i)) myset.insert(i);
            else myset.erase(i);
        }
        return *myset.begin();
    }
};
// O(n) O(n)