class Solution {
public:
    bool digitCount(string num) {
        vector<int> vec(10);
        for (const auto& n : num) {
            vec[n - '0']++;
        }
        for (int i = 0; i < num.size(); ++i) {
            if (vec[i] != num[i] - '0') return false;
        }
        return true;
    }
};