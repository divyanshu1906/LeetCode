class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int, int>mpp;
        mpp[0]=-1;
        int ans = nums.size();
        int total_sum = 0;
        int prefix_sum = 0;
        for(auto n : nums){
            total_sum = (total_sum + n)%p;
        }
        if(total_sum == 0) return 0;
        for(int i=0; i<nums.size(); i++){
            prefix_sum = (prefix_sum + nums[i])%p;
            int check = (prefix_sum - total_sum + p)%p;
            if(mpp.find(check)!=mpp.end()){
                ans = min(ans, i-mpp[check]);
            }
            mpp[prefix_sum] = i;
        }
        if(ans == nums.size()) return -1;
        else return ans;
    }
};