class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0, maxDiff=0, maxi=0;
        
        for(int i=0; i<n; i++){
            ans = max(ans, maxDiff*nums[i]);
            maxDiff = max(maxDiff, maxi-nums[i]);
            maxi = max(maxi, (long long )nums[i]);
        }
        return ans;
    }
};