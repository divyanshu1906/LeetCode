#include<bits/stdc++.h>
class Solution {
public:
    long long min_days(vector<int>&arr, int mid){
        int n = arr.size();
        int ans = 0;
        long long hours = 0;
        for(int i=0; i<n; i++){
            hours += ceil((double) arr[i] / (double)mid);
        } 
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int mini = 1;
        int maxi = INT_MIN;
        int ans = -1;
        for(int i=0; i<n; i++){
            maxi = max(maxi, piles[i]);
        }
        int low = mini, high = maxi;
        while(low <= high){
            int mid = low + (high-low)/2;
            long long result = min_days(piles, mid);
            if(result <= h){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};