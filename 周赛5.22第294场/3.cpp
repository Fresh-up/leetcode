class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        if (stockPrices.size() == 1) return 0;
        int mlines = 1;
        sort(stockPrices.begin(), stockPrices.end());
        long long k1 = stockPrices[1][1] - stockPrices[0][1], k2 = stockPrices[1][0] - stockPrices[0][0];
        for (int i = 2; i < stockPrices.size(); ++i) {
            long long kk1 = stockPrices[i][1] - stockPrices[i - 1][1];
            long long kk2 = stockPrices[i][0] - stockPrices[i - 1][0];
            if (kk1 * k2 != kk2 * k1) {
                k1 = kk1;
                k2 = kk2;
                ++mlines;
            }
        }
        return mlines;
    }
};