class Solution {
public:
    const int MOD = 1000000007;
    int numSub(string s) {
        int ans = 0;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i]=='1'){
                int j=i;
                while(j<n && s[j]!='0' ){
                    j++;
                }
                int idx = j-i;
                ans = (ans+1LL*idx*(idx+1)/2)%MOD;
                i=j-1;
            }
        }
        return ans%MOD;
    }
};