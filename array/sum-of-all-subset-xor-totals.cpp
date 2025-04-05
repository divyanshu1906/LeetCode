class Solution {
public:
    int backTracking(int idx, int xorSum, vector<int>&nums){
        if(idx>=nums.size()) {
            return xorSum;
        }

        int take = backTracking(idx+1, xorSum^nums[idx], nums);
        int notTake = backTracking(idx+1, xorSum, nums);

        return take+notTake;
    }
    int subsetXORSum(vector<int>& nums) {
        
        return backTracking(0, 0, nums);
    }
};