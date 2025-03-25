class Solution {
public:
    void findingValidString(int idx, int n, string str, unordered_set<string>&st){
        if(idx==n){
            st.insert(str);
            return;
        }
        for(char ch = '0'; ch<='1'; ch++){
            if(str.back()=='0'){
                str+='1';
                findingValidString(idx+1, n, str, st);
                str.pop_back();
            }else{
                str+=ch;
                findingValidString(idx+1, n, str, st);
                str.pop_back();
            }
        }
    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        string str = "";
        unordered_set<string>st;
        for(char ch = '0'; ch<='1'; ch++){
            str += ch;
            findingValidString(1, n, str, st);
            str.pop_back();
        }
        for(auto str: st){
            ans.push_back(str);
        }
        return ans;
    }
};