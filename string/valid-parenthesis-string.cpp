class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int low = 0, high =0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                low++;
                high++;
            }
            else if(s[i]==')'){
                low = max(0, low-1);
                high--;
            }
            else{
                low = max(0, low-1);
                high++;
            }
        }
        if(high<0) return false;
        return low==0;
    }
};