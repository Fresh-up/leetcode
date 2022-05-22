class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int k = 0;
        for (int i = 0; i < capacity.size(); ++i) {
            capacity[i] -= rocks[i];
        }
        sort(capacity.begin(), capacity.end());
        for (; k < capacity.size(); ++k) {
            if (capacity[k] > 0) {
                if (additionalRocks < capacity[k]) break;
                else {
                    additionalRocks -= capacity[k];
                }
            }
        }
        return k;
    }
};