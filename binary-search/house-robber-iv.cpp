class Solution {
public:
    int n;
    bool isPossible(int mid, vector<int>& nums, int k){
        for(int i=0; i<n; i++){
            if(nums[i]<=mid) k--, i++;
        }
        return k<=0 ? true : false;
    }
    int minCapability(vector<int>& nums, int k) {
        n = nums.size();
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        int result = r;
        while(l<=r){
            int mid = l + (r-l)/2;

            if(isPossible(mid, nums, k)){
                result = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }

        }
        return result;
    }
};