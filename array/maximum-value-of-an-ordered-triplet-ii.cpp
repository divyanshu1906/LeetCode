class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0, minDiff=0, maxi=0;
        for(int i=0; i<nums.size(); i++){
            ans = max(ans, minDiff*nums[i]);
            minDiff = max(minDiff, maxi-nums[i]);
            maxi = max(maxi, (long long)nums[i]);
        }
        return ans;
    }
};