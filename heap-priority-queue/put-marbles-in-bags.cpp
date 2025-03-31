class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        if(k==1) return 0;
        int n = weights.size();
        
        vector<int>pairSum;
        for(int i=0; i<n-1; i++){
            pairSum.push_back(weights[i]+weights[i+1]);
        }
        sort(begin(pairSum), end(pairSum));

        long long minScore = accumulate(pairSum.begin(), pairSum.begin() + (k-1), 0LL);
        long long maxScore = accumulate(pairSum.end() - (k-1), pairSum.end() , 0LL);

        return maxScore - minScore;
    }
};