class Solution {
public:
    bool oneEditAway(string first, string second) {
        int nf = first.size(), ns = second.size();
        if (abs(nf - ns) > 1) return false;
        int i = 0, n = nf > ns ? ns : nf;
        while (i < n) {
            if (first[i] != second[i]) {
                string tf, ts;
                if (nf > ns) {
                    tf = first.substr(i + 1, nf - i - 1);
                    ts = second.substr(i, ns - i);
                }
                else if (nf < ns) {
                    tf = first.substr(i, nf - i);
                    ts = second.substr(i + 1, ns - i - 1);
                }
                else {
                    tf = first.substr(i + 1, nf - i - 1);
                    ts = second.substr(i + 1, ns - i - 1);
                }
                if (tf == ts) return true;
                else return false;
            }
            ++i;
        }
        return true;
    }
};
// O(n) O(1)