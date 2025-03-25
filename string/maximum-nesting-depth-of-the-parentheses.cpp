class Solution {
public:
    int maxDepth(string s) {
        int maxCount=0;
        int curr=0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '(') curr++;
            else if(s[i] == ')') curr--;
            maxCount = max(maxCount, curr);
        }
        return maxCount;
    }
};