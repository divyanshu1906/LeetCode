class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0; i<n; i++){
            totalSum += nums[i];
        }
        if(totalSum % 2 != 0) return false;
        int target = totalSum/2;
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
        for(int i=0; i<=n; i++){
            dp[i][0] = true;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=target; j++){
                bool notTake = dp[i-1][j];
                bool take = false;
                if(j>=nums[i-1]){
                    take = dp[i-1][j-nums[i-1]];
                }
                dp[i][j] = take||notTake;
            }
        }
        return dp[n][target];
    }
};