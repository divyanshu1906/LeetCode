class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.size();
        vector<int>last(10,-1);
        for(int i=0; i<n; i++){
            last[str[i]-'0'] = i;
        }
        for(int i=0; i<str.length(); i++){
            for(int j=9; j>str[i]-'0'; j--){
                if(last[j]>i){
                    swap(str[i], str[last[j]]);
                    return stoi(str);
                }
            }
        }
        return num;
    }
};