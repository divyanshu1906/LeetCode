class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int m = skill.size();
        int n = mana.size();
        vector<vector<long long>>dp(n, vector<long long>(m, 0));

        for(int i=0; i<n; i++){
            long long prevSum = 0;
            for(int j=0; j<m; j++){
                prevSum += (long long)mana[i] * (long long)skill[j];
                if(i-1>=0){
                    prevSum = max(prevSum, dp[i-1][j]+(long long)mana[i] * (long long)skill[j]);
                }
                dp[i][j] = prevSum;
            }
            for(int j=m-2; j>=0; j--){
                dp[i][j] = dp[i][j+1]-(long long)skill[j+1]*(long long)mana[i];
            }
        }
        return dp[n-1][m-1];
    }
};