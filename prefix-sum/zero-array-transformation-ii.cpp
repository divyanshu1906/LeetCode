class Solution {
public:
    int n,q;
    bool checkDifferenceArrayTech(vector<int>& nums, vector<vector<int>>& queries, int k){
        vector<int>diff(n,0);
        for(int i=0; i<=k; i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int value = queries[i][2];
            diff[l] += value;
            if(r+1<n) diff[r+1] -= value;
        }
        int cumSum = 0;
        for(int i=0; i<n; i++){
            cumSum += diff[i];
            diff[i] = cumSum;
            if(nums[i]-diff[i]>0) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        q = queries.size();

        auto lambda = [](int x){
            return x==0;
        };
        if(all_of(nums.begin(), nums.end(), lambda)) return 0;

        int l=0, r=q-1, k=-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(checkDifferenceArrayTech(nums, queries, mid)){
                k = mid+1;
                r = mid-1;
            }else{
                l=mid+1;
            }
        }
        return k;
    }
};