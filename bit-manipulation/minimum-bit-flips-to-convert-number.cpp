class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        int xo = start ^ goal;
        while(xo!=0){
            ans += xo&1;
            xo>>=1;
        }
        return ans;
    }
};