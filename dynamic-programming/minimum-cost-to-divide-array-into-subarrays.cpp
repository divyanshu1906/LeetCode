class Solution {
public:
    int n;
    long long findingMinimumCostSubarray(int idx, int partitionIdx, vector<int>&nums, vector<int>&cost, vector<int>&prefixSum, int k){
        if(idx==n){
            return 0;
        }
        long long minCost = LLONG_MAX;
        long long totalCost = 0;
        for(int i=idx; i<n; i++){
            totalCost += cost[i]; 
            
            int sum = prefixSum[i];
            long long currentCost = (1LL * (sum + k * partitionIdx)) * totalCost;

            long long recCost = findingMinimumCostSubarray(i+1, partitionIdx+1, nums, cost, prefixSum, k);
            minCost = min(minCost, currentCost+recCost);
        }
        
        return minCost;
    }
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        n = nums.size();

        vector<int>prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        return findingMinimumCostSubarray(0, 1, nums, cost, prefixSum, k);
    }
};