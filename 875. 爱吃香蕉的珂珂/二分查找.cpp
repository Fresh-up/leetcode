class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = 0;
        long long ssum = 0;
        for (int pile : piles) {
            high = max(high, pile);
            ssum += pile;
        }
        int low = max(ssum / h - 1, (long long)1);

        int k = high;
        while (low < high) {
            int speed = (high - low) / 2 + low;
            long long time = gettime(piles, speed);
            if (time <= h) {
                k = speed;
                high = speed;
            } else low = speed + 1;
        }
        return k;
    }
    long long gettime(const vector<int>& piles, int speed) {
        long long time = 0;
        for (int pile : piles) {
            int curtime = (pile + speed - 1) / speed;
            time += curtime;
        }
        return time;
    }
};
// 二分查找O(nlogm) O(1)