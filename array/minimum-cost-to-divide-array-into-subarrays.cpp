class Solution {
public:
    int n;

    long long findingMinimumCostSubarray(int idx, int partitionIdx, vector<int>&prefixSum, vector<int>&costSum, int k, vector<long long>&dp){
        if(idx==n){
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];

        long long minCost = LLONG_MAX;

        for(int i=idx; i<n; i++){
            long long sumTill = prefixSum[i];
            long long totalCost = idx == 0 ? costSum[i] : costSum[i] - costSum[idx - 1];
            long long costTillLast = idx==0 ? costSum[n-1] : costSum[n-1] - costSum[idx -1];

            long long currentCost = (sumTill * totalCost) + (k*costTillLast);
            long long recCost = findingMinimumCostSubarray(i+1, partitionIdx+1, prefixSum, costSum, k, dp);
            minCost = min(minCost, currentCost+recCost);
        }
        
        return dp[idx] = minCost;
    }
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        n = nums.size();

        vector<int>prefixSum(n, 0);
        vector<int>costSum(n, 0);
        prefixSum[0] = nums[0];
        costSum[0] = cost[0];
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
            costSum[i] = costSum[i-1] + cost[i];
        }
        vector<long long>dp(n+1, -1);
        return findingMinimumCostSubarray(0, 1, prefixSum, costSum, k, dp);
    }
};