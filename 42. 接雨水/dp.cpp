// 思路是只要知道每一个元素对应的最大左值和最大右值，该处的最大水量就是
// min(最大左值，最大右值) - height[i]
// 动态规划，leftmax记录每个位置的最大左值，rightmax记录每个位置的最大右值

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int size = height.size();
        vector<int> leftmax(size, 0);
        vector<int> rightmax(size, 0);
        leftmax[0] = height[0];
        rightmax[size - 1] = height[size - 1];
        for (int i = 1; i < size; ++i) {
            leftmax[i] = max(leftmax[i - 1], height[i]);
            rightmax[size - i - 1] = max(rightmax[size - i], height[size - i - 1]);
        }
        for (int i = 1; i < size - 1; ++i) {
            ans += min(leftmax[i], rightmax[i]) - height[i];
        }
        return ans;
    }
};
// O(n) O(n)