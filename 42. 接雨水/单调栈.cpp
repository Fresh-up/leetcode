class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;// 存储的是下标
        // 底部的下标对应的高度大，顶部的小
        int res = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!stk.empty() && height[i] > height[stk.top()]) {
                int top = stk.top();
                stk.pop();
                if (stk.empty()) break;
                int left = stk.top();
                int high = min(height[left], height[i]) - height[top];
                int width = i - left - 1;
                res += high * width;
            }
            stk.push(i);
        }
        return res;
    }
};
// O(n) O(n)