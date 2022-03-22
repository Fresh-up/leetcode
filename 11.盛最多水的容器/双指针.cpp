#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxa = 0;
        int area = 0;
        int n = height.size() - 1;
        int left = 0, right = n;
        while (left < right){
            area = n * min(height[left], height[right]);
            maxa = max(area, maxa);
            --n;
            if (height[left] <= height[right]) ++left;
            else --right;
        }
        return maxa;
    }
};
//时间复杂度O(N),空间复杂度O(1)