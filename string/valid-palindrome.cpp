class Solution {
public:
    bool f(string &s, int i, int j){
        if(i>j){
            return true;
        }

        //processing

        //1. ignore if not alphanumeric

        if(!isalnum(s[i])){
           return f(s, i+1, j);
        }

        if(!isalnum(s[j])){
           return f(s, i, j-1);
        }
       //yaha tak pahuchna means digit is alphanumeric
        
        if(tolower(s[i])!=tolower(s[j])){
            return false;
        }

        //rr

        return f(s, i+1, j-1);
    }
    bool isPalindrome(string s) {
        int n= s.size();
       return f(s,0,n);
    }
};