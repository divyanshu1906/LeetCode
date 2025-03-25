class Solution {
public:
    long long minimumSteps(string s) {
        int blackCount= 0;
        long long ans=0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '0'){
                ans += (long)(long)blackCount;
            }
            else{
                blackCount++;
            }
        }
        return ans;
    }
};