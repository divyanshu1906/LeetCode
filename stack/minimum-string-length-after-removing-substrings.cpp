class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(char str : s){
            if(st.empty()){
                st.push(str);
                continue;
            }
            if(str == 'B' && st.top()=='A'){
                st.pop();
            }
            else if(str=='D' && st.top()=='C'){
                st.pop();
            }
            else{
                st.push(str);
            }
        }
        return st.size();
    }
};