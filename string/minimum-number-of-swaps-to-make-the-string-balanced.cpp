class Solution {
public:
    int minSwaps(string s) {
        int open = 0, unbalanced = 0;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(ch=='[')open++;
            else if( open!=0){
                open--;
            }
            else{
                unbalanced++;
            }
        }
        return (unbalanced+1)/2;
    }
};