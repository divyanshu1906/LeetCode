class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        for(auto n : nums){
            mpp[n]++;
        }
        for(auto n : mpp){
            if(n.second==1) ans.push_back(n.first);
        }
        return ans;
    }
};