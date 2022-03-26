#include<vector>
#include<stack>
using namespace std;
/*
思路：用栈来模拟输入的情况，加几句if逻辑即可*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int pop = 0, push = 0;
        while(push < pushed.size()){
            if (pushed[push] == popped[pop]){
                ++pop;
                ++push;
            }
            else if(!stk.empty() && popped[pop] == stk.top()){
                stk.pop();
                ++pop;
            }
            else {
                stk.push(pushed[push]);
                ++push;
            }
        }
        while (!stk.empty() && stk.top() == popped[pop]){
            stk.pop();
            ++pop;
        }
        return stk.empty();
    }
};