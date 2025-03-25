class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int l=0, r=1;
        int currOR = nums[l];
        int maxAns = 1;
        while(r<n){
            while((currOR & nums[r]) != 0){
                currOR ^= nums[l];
                l++;
            }
            currOR |= nums[r];
            maxAns = max(maxAns, r-l+1);
            r++;
        }
        return maxAns;
    }
};