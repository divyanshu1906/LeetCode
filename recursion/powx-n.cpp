class Solution {
public:
    double myPow(double x, long n) {
        double ans = 1;
        if(n<0){
            x = 1/x;
            n *= -1;
        }
        while(n!=0){
            if(n&1){
                ans *= x;
            }
            x=x*x;
            n=n>>1;
        }
        return ans;
    }
};