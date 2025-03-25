class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mpp;
        int ans = 0;
        bool flag = false;
        for(int i=0; i<n; i++){
            if(nums[i]>0){ 
                flag = true;
                mpp[nums[i]]++;
                if(mpp[nums[i]] == 1){
                    ans += nums[i];
                }
            }
        }
        if(!flag){
            ans = INT_MIN;
            for(int i=0; i<n; i++){
                ans = max(ans, nums[i]);
            }
        }
        return ans;
    }
};