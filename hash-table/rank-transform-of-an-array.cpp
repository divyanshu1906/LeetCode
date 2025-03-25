class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>cpy=arr;
        sort(cpy.begin(), cpy.end());
        unordered_map<int, int>mpp;
        int i=0, n=arr.size(), rank=1;
        while(i<n){
            if(i==0){}
            else if(cpy[i]==cpy[i-1]){}
            else rank++;
            mpp[cpy[i]] = rank;
            i++;
        }
        for(auto &x:arr){
            x = mpp[x];
        }
        return arr;
    }
};