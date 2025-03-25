class Solution {
public:
    bool isPalindrome(int x) {
        int last_digit, m;
        long sum=0;
        m=x;
        if(x<0) return false;
        while(x!=0)
        {
            last_digit=x%10;
            sum=sum*10+last_digit;
            x=x/10;
        }
        if(m==sum) return true;
        else return false;
    }
};