class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i=0,j=0;
        int currSum = 0;
        int length=INT_MAX;
        while(i<n){
            currSum += nums[i];
            while(currSum >= target){
                length = min(length, i-j+1);
                currSum -= nums[j];
                j++;
            }
            
            i++;
        }
        return length>n ? 0 : length;
    }
};