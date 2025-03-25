class Solution {
public:
    bool isPossible(int idx, vector<int>&nums, int currSum, int totalSum, vector<vector<int>>&dp){
        if(idx==nums.size()){
            int remSum = totalSum - currSum;
            return remSum == currSum ? true : false;
        }
        
        if(dp[idx][currSum] != -1) return dp[idx][currSum];
        bool take = isPossible(idx+1, nums, currSum+nums[idx], totalSum, dp);
        bool notTake = isPossible(idx+1, nums, currSum, totalSum, dp);

        return dp[idx][currSum] = take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0; i<n; i++){
            totalSum += nums[i];
        }
        vector<vector<int>>dp(n, vector<int>(totalSum+1, -1));
        return isPossible(0, nums, 0, totalSum, dp);
    }
};