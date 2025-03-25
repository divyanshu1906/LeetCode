class Solution {
public:
    int n;
    bool isPossible(vector<int>& ranks, long long mid, int cars){
        long long carFixed = 0;
        for(int i=0; i<n; i++){
            carFixed += sqrt(mid/ranks[i]);
        }
        return carFixed>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        n = ranks.size();
        int maxR = *max_element(ranks.begin(), ranks.end());
        long long l = 1, h = 1LL * maxR * cars * cars;
        long long ans = -1;
        while(l<=h){
            long long mid = l + (h-l)/2;
            if(isPossible(ranks, mid, cars)){
                ans = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};