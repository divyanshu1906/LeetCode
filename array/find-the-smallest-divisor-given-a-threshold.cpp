class Solution {
public:
    int sDivisior(vector<int> &arr, int mid, int threshold, int n){
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += ceil((double)arr[i]/(double)mid);
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
        }
        int low = 1, high = maxi;
        while(low<=high){
            int mid = low + (high-low)/2;
            int result = sDivisior(nums, mid, threshold, n);
            if(result <= threshold){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};