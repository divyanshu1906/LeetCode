class Solution {
public:
    long long calculatingPoints(int idx, vector<vector<int>>& questions, vector<int>&dp){
        if(idx>=questions.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        long long take = questions[idx][0] + calculatingPoints(idx+questions[idx][1]+1, questions, dp);
        long long notTake = calculatingPoints(idx+1, questions, dp);
        return dp[idx] = max(take, notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n, -1);
        return calculatingPoints(0, questions, dp);
    }
};