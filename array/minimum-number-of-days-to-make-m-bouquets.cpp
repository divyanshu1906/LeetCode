class Solution {
public:
    bool no_boquet(vector<int>&arr, int mid, int m, int k, int n){
        int count = 0;
        int boquet = 0;
        for(int i=0; i<n; i++){
            if(arr[i] <= mid){
                count++;
            }
            else{
                boquet += count/k;
                count = 0;
            }
        }
        boquet += count/k;
        if(boquet >= m ){
            return true;
        }
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long b = (double)m*(double)k;
        if(n < b)return -1;
        int ans = -1;
        int maxi = INT_MIN, mini = INT_MAX;
        for(int i=0; i<n; i++){
            maxi = max(maxi, bloomDay[i]);
            mini = min(mini, bloomDay[i]);
        }
        int low = mini, high = maxi;
        while(low<=high){
            int mid = low + (high-low)/2;
            bool result = no_boquet(bloomDay, mid, m, k, n);
            if(result){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};