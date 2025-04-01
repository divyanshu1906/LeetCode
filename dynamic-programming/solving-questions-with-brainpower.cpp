class Solution {
public:
    long long calculatingPoints(int idx, vector<vector<int>>& questions){
        if(idx>=questions.size()) return 0;
        long long take = questions[idx][0] + calculatingPoints(idx+questions[idx][1]+1, questions);
        long long notTake = calculatingPoints(idx+1, questions);
        return max(take, notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        return calculatingPoints(0, questions);
    }
};