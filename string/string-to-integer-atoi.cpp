class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        bool flag = false;
        int i=0;
        long ans = 0;
        while(i<n && s[i]==' '){
            i++;
        }
        if(i<n && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-') flag = true;
            i++;
        } 
        while(i<n && isdigit(s[i])){
            ans= ans*10+(s[i]-'0');
            i++;
            if(ans > INT_MAX){
                return flag? INT_MIN : INT_MAX;
            }
        }
        if(flag){
            ans = -ans;
        }
        return static_cast<int>(ans);
    }
};