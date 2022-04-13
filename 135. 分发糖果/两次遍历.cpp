#include <vector>
#include <algorithm>
#include <numeric>//包含accumulate
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> vec(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i){
            if (ratings[i] > ratings[i-1])
                vec[i] = vec[i-1] + 1;
        }
        for (int i = ratings.size() - 2; i >= 0; --i){
            // if (ratings[i] > ratings[i+1] && vec[i] <= vec[i+1])
            //     ++vec[i];
            if (ratings[i] > ratings[i+1])
                vec[i] = max(vec[i], vec[i+1]+1);
        }
        return accumulate(vec.begin(), vec.end(), 0);
    }
};
//O(n) O(n)