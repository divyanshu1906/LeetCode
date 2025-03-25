class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        if(n<3) return n;
        int ans=0;
        unordered_map<char, int>mpp;
        for(int i=0; i<n; i++){
            char ch = s[i];
            mpp[ch]++;
        }
        for(auto it : mpp){
            int num = it.second;
            if(num >= 3){
                if(num%2==0)ans+=2;
                else ans+=1;
            }
            else ans += num;
        }
        return ans;
    }
};