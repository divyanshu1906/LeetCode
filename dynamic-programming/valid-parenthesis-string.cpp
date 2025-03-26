class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<int>st(3,0);
        for(int i=0; i<n; i++){
            if(s[i]=='(')st[0]++;
            else if(s[i]=='*')st[1]++;
            else st[2]++;
        }
        if(st[0]==st[2]) return true;
        else if(st[0]+st[1] == st[2]) return true;
        return false;
    }
};