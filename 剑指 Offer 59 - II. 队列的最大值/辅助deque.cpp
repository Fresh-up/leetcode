class MaxQueue {
    queue<int> q;
    deque<int> d;
public:
    MaxQueue() {

    }
    
    int max_value() {
        if (q.size() == 0) return -1;
        else return d.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while (!d.empty() && value > d.back()) d.pop_back();
        d.push_back(value);
    }
    
    int pop_front() {
        if (q.size() == 0) return -1;
        int qq = q.front();
        if (qq < d.front()) {
            q.pop();
        } else {
            q.pop();
            d.pop_front();
        }
        return qq;
    }
};