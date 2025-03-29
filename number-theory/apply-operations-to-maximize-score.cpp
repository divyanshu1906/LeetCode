class Solution {
public:
    const int MOD = 1000000007;
    int findingPrimeFactor(int n){
        int uniquePrimeFactor = 0;
        for (int div = 2; div * div <= n; div++) {
            if (n % div == 0) {
                uniquePrimeFactor++;
                while (n % div == 0) {
                    n /= div;
                }
            }
        }
        if (n > 1) uniquePrimeFactor++;  
        return uniquePrimeFactor;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<vector<int>>pq;
        unordered_map<int, int>mpp;
        for(int i=0; i<n; i++){
            if(mpp.find(nums[i]) == mpp.end()){
                mpp[nums[i]] = findingPrimeFactor(nums[i]);
            }
            pq.push({nums[i], i, mpp[nums[i]]});
        }

        long long ans = 1;

        while(k>0 && !pq.empty()){
            vector<int>top = pq.top();
            pq.pop();

            int ele = top[0];
            int idx = top[1];
            int primeFactor = top[2];
            
            ans = (ans*ele)%MOD;
            k--;

            int left = idx-1;
            int right = idx+1;
            while(right<n && k>0){
                if(mpp[nums[right]] <= primeFactor){
                    ans = (ans*ele)%MOD;
                    k--;
                }
                else break;
                right++;
            }
            while(left>=0 && k>0){
                if(mpp[nums[left]]<primeFactor){
                    ans=(ans*ele)%MOD;
                    k--;
                }
                else break;
                left--;
            }

        }
        return static_cast<int>(ans);
    }
};