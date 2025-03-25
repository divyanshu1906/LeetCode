class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }
        for(auto it : mpp){
            int freq = it.second;
            if(freq%2 != 0) return false;
        }
        return true;
    }
};