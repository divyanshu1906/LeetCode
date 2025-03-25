class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0, count=0;
        map<int, int> mpp;
        mpp[0] = 1;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            int res = sum-k;
            count+=mpp[res];
            mpp[sum]+=1;
        }
        return count;
    }
};