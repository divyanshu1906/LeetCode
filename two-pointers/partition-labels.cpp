class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        unordered_map<char, int>mpp;
        for(int i=n-1; i>=0; i--){
            char ch = s[i];
            if(mpp.find(ch) == mpp.end()){
                mpp[ch] = i;
            }
        } 

        vector<int>ans;
        int start=0, end=0;
        for(int i=1; i<n; i++){
            end = max(end, mpp[s[i]]);
            if(i==end){
                ans.push_back(end-start+1);
                start = i+1;
            }
        }

        return ans;
    }
};