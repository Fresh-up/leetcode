class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mymap;
        stack<int> stk;
        vector<int> res;
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];
            while (!stk.empty() && num > stk.top()) {
                stk.pop();
            }
            mymap[num] = stk.empty() ? -1 : stk.top();
            stk.push(num);
        }
        for (const int& n : nums1) res.emplace_back(mymap[n]);
        return res;
    }
};
// O(n) O(n)