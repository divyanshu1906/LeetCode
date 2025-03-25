class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int r=0, l=0;
        int maxCount = 0;
        while(l<n){
            if(nums[l]==0 && k!=0){
                k--;
            }
            else if(nums[l]==0 && k==0){
                while(r<=l){
                    if(nums[r]==0){
                        r++;
                        break;
                    }
                    r++;
                }
            }
            maxCount = max(maxCount, l-r+1);
            l++;
        }
        return maxCount;
    }
};