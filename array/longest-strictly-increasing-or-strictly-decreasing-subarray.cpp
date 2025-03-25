class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_length=1, curr_length=1;
        for(int i=1; i<n; i++){
            if(nums[i]!=nums[i-1]){
                if(nums[i]>nums[i-1]){
                    if(i==1 || nums[i-1] < nums[i-2]){
                        curr_length=2;
                    }
                    else {
                        curr_length++;
                    }
                }
                else{
                    if(i==1 || nums[i-1] > nums[i-2]){
                        curr_length=2;
                    }
                    else {
                        curr_length++;
                    }
                }
            }
            else{
                curr_length= 1;
            }
            max_length = max(max_length, curr_length);
        }
        return max_length;
    }
};