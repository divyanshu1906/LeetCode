class Solution {
public:
    int backTracking(int index, int currOr, vector<int>&nums,int xorSum){
        if(index==nums.size()){
            if(currOr == xorSum) return 1;
            return 0;
        }
        int taken = backTracking(index+1, currOr|nums[index], nums, xorSum);
        int notTaken = backTracking(index+1, currOr, nums, xorSum);

        return taken + notTaken;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int xorSum = 0;
        for(int i=0; i<nums.size(); i++){
            xorSum = xorSum | nums[i];
        }
        return backTracking(0, 0, nums, xorSum);
    }
};