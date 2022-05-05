class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mymap;
        int n = nums.size() / 2;
        for (const int& i : nums){
            ++mymap[i];
            if (mymap[i] > n) return i;
        }
        return 0;
    }
};
// O(n) O(n)