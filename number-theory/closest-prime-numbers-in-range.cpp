class Solution {
public:
    bool checkPrime(int n){
        if(n<2) return false;
        for(int i=2; i*i<=n; i++){
            if(n%i==0)return false;
        }
        return  true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>prime;
        vector<int>result={-1,-1};
        int minDiff = INT_MAX;
        
        for(int i=left; i<=right; i++){
            if(checkPrime(i)){
                prime.push_back(i);
            }
        }
        for(int i=1; i<prime.size(); i++){
            int diff = prime[i] - prime[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result[0] = prime[i - 1];
                result[1] = prime[i];
            }
        }
        return result;
    }
};