class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum = 0;
        int currMax = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i-1] < nums[i]){
                currMax += nums[i];
            }
            else{
                maxSum = max(maxSum, currMax);
                currMax = nums[i];
            }
        }
        maxSum = max(maxSum, currMax);
        return maxSum;
    }
};