class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MIN;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    long long currAns = ((long long)nums[i]-(long long)nums[j])*(long long)nums[k];
                    ans = max(ans, currAns);
                }
            }
        }
        return ans>0 ? ans : 0;
    }
};