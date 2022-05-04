class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l=0,r=0,maxl=0;
        int cnt[2]={0};//0-F,1-T
        // cnt是记录在[l, r]区间内F和T的个数的数组
        int size=answerKey.size();
        for(r=0;r<size;r++){
            cnt[answerKey[r]=='T']++;
            if(k<min(cnt[1],cnt[0])){
                // 当[l, r]中最少的符号比k大，说明k已经无法覆盖该区域
                cnt[answerKey[l]=='T']--;
                l++;
            }
        }
        return r-l;
    }
};
// O(n) O(1)