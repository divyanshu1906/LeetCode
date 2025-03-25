class Solution {
public:
    bool findingMaximumCandies(vector<int>& candies, long long k, int mid){
        int n = candies.size();
        long long divisibleAns = 0;
        for(int i=0; i<n; i++){
            divisibleAns += candies[i]/mid;
            if(divisibleAns >= k) return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int low = 1;
        long long sumCandies = accumulate(candies.begin(), candies.end(), 0LL);
    int high = (int)min((long long)*max_element(candies.begin(), candies.end()), sumCandies / k);
        int ans = 0;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(findingMaximumCandies(candies, k, mid)){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};