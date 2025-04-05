class Solution {
public:
    int n;
    long long findingMinimumCostSubarray(int idx, int partitionIdx, vector<int>&nums, vector<int>&cost, vector<int>&prefixSum, int k, vector<vector<long long>>&dp){
        if(idx==n){
            return 0;
        }
        if(dp[idx][partitionIdx] != -1) return dp[idx][partitionIdx];

        long long minCost = LLONG_MAX;
        long long totalCost = 0;

        for(int i=idx; i<n; i++){
            totalCost += cost[i]; 
            
            long long currentCost = (1LL * (prefixSum[i] + k * partitionIdx)) * totalCost + findingMinimumCostSubarray(i+1, partitionIdx+1, nums, cost, prefixSum, k, dp);
            minCost = min(minCost, currentCost);
        }
        
        return dp[idx][partitionIdx] = minCost;
    }
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        n = nums.size();

        vector<int>prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        vector<vector<long long>>dp(n+1, vector<long long>(n+1, -1));
        return findingMinimumCostSubarray(0, 1, nums, cost, prefixSum, k, dp);
    }
};