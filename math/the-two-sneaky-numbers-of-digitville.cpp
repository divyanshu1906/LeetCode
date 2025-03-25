class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int>mpp;
        vector<int>ans;
        for(auto n : nums){
            mpp[n]++;
        }
        for(auto n : mpp){
            if(n.second == 2){
                ans.push_back(n.first);
            }
        }
        return ans;
    }
};