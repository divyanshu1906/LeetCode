class Solution {
public:
    int minDay(vector<int>& arr, int mid, int days, int n){
        int count = 1, sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum > mid){
                count++;
                sum = 0;
                sum += arr[i];
            }
        }return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxi = INT_MIN, sum=0, ans =-1;
        for(int i=0; i<n; i++){
            maxi = max(maxi, weights[i]);
            sum += weights[i];
        }
        int low = maxi, high = sum;
        while(low <= high){
            int mid = low + (high - low)/2;
            int result = minDay(weights, mid, days, n);
            if(result <= days){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};