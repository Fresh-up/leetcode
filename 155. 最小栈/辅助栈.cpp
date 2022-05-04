// 对于栈中的每一个元素肯定都对应着一个最小值，压入辅助栈
class MinStack {
private:
    stack<int> mstk;
    stack<int> stk;
public:
    MinStack() {
        mstk.push(INT_MAX)
    }
    
    void push(int val) {
        stk.push(val);
        mstk.push(min(mstk.top(), val));
    }
    
    void pop() {
        stk.pop();
        mstk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return mstk.top();
    }
};