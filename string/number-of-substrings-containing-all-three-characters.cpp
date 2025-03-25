class Solution {
public:
    bool check(vector<int>&freq){
        for(int i=0; i<3; i++){
            if(freq[i]==0) return false;
        }
        return true;
    }
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int i=0, j=0;
        vector<int>freq(3);
        while(j<n){
            char ch = s[j];
            freq[ch-'a']++;
            while(check(freq)){
                ans += n-j;
                char ch = s[i];
                freq[ch-'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};