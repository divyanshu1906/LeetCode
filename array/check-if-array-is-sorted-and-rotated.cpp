class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int smallestElement = INT_MAX;
        int idx = -1;
        vector<int>ans = nums;
        sort(ans.begin(), ans.end());
        int l=0, r=0;
        while((r<n)){
            if(l>=2*n) return false;
            if(nums[l%n] == ans[r]){
                l++;
                r++;
            }
            else{
                l++, r=0;
            }
        }
        return r==n?true:false;
    }
};