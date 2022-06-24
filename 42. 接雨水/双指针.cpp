// 双指针，看代码还是比较容易理解
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int maxleft = 0, maxright = 0;
        while (left < right) {
            maxleft = max(maxleft, height[left]);
            maxright = max(maxright, height[right]);
            if (height[left] < height[right]) {
                // 一旦right到达了整个数组的最大值，就会停下来了
                ans += maxleft - height[left];
                ++left;
            } else {
                ans += maxright - height[right];
                --right;
            }
        }
        return ans;
    }
};
// O(n) O(1)