// 此题简单，跟以前做过的一道题类似
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> mymap;
        int minnum = INT_MAX;
        int num = 0;

        for (int i = 0; i < cards.size(); ++i){
            if (!mymap.count(cards[i])) mymap[cards[i]] = i;
            else {
                num = i - mymap[cards[i]] + 1;
                minnum = min(minnum, num);
                mymap[cards[i]] = i;
            }
        }
        if (minnum == INT_MAX) return -1;
        else return minnum;
    }
};