class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>mpp;
        for(int i=0; i<nums.size(); i++){
            int comp = target-nums[i];
            mpp.insert({nums[i], i});
            if(mpp.find(comp)!= mpp.end() && mpp[comp] != i){
                return {i,mpp[comp]};
            }
            mpp[nums[i]]=i;
        }
        return {-1,-1};
    }
};