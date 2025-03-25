class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int l=0, r=0;
        int maxSum = INT_MIN, sum=0;
        while(r<n){
            sum += nums[r];
            if(sum<0){
                l++,r++;
                maxSum = max(maxSum, sum);
                sum = 0;
            }
            else{
                maxSum = max(maxSum, sum);
                r++;
            }
        }
        return maxSum;
    }
};