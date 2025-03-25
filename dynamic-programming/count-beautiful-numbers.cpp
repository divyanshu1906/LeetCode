class Solution {
public:
    unordered_map<string, int>dp;
    int solve(string &str, int idx, int tight, int sum, int pro){
        if(idx==str.size()){
            return (sum>0 && pro%sum==0);
        }

        string key = to_string(idx)+"+"+to_string(tight)+"+"+to_string(sum)+"+"+to_string(pro);

        if(dp.find(key) != dp.end()) return dp[key];

        int ans = 0;

        int limit = (tight==1) ? str[idx]-'0' : 9;
        for(int i=0; i<=limit; i++){
            int updatedPro = i*pro;
            if(i+sum==0) updatedPro = 1;
            ans += solve(str, idx+1, (tight & (limit==i)), sum+i, updatedPro) ;
        }
        return dp[key] = ans;
    }
    int beautifulNumbers(int l, int r) {
        string ri = to_string(r);
        int rightAns = solve(ri, 0, 1, 0, 1);
        dp.clear();
        string li = "0";
        if(l>0) li = to_string(l-1);
        int leftAns = solve(li, 0, 1, 0, 1);
        return rightAns-leftAns;
    }
};