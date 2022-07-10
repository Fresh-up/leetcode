class SmallestInfiniteSet {
    set<int> in;
    set<int> out;
public:
    SmallestInfiniteSet() {

    }
    
    int popSmallest() {
        if (in.empty()) {
            if (out.empty()) {
                out.insert(1);
                return 1;
            } else {
                int t = *out.rbegin() + 1;
                out.insert(t);
                return t;
            }
        } else {
            int t = *in.begin();
            out.insert(t);
            in.erase(t);
            return t;
        }
    }
    
    void addBack(int num) {
        if (out.count(num)) {
            out.erase(num);
            in.insert(num);
        }
    }
};