class Solution {
public:
    bool recursion(int i, int j, int val, vector<int>& nums, vector<vector<int>>& queries, vector<vector<vector<int>>>&dp){
        if(val==0) return true;
        if(i==-1) return false;

        if(dp[i][j][val] != -1) return dp[i][j][val];

        bool withoutQueries = recursion(i-1, j, val, nums, queries, dp);

        int li = queries[i][0], ri = queries[i][1], qval = queries[i][2];

        bool withQueries = false;
        if(li<=j && j<=ri && qval <= val){
            withQueries = recursion(i-1, j, val-qval, nums, queries, dp);
        }

        return dp[i][j][val] = withoutQueries || withQueries;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        int maxValue = *max_element(nums.begin(), nums.end());
        if(maxValue==0) return 0;
        
        vector<vector<vector<int>>>dp(q, vector<vector<int>>(n, vector<int>(maxValue+1, -1)));

        for(int i=0; i<q; i++){
            bool flag = true;
            for(int j=0; j<n; j++){
                if(!(recursion(i, j, nums[j], nums, queries, dp))){
                    flag = false;
                    break;
                }
            }
            if(flag) return i+1;
        }
        return -1;
    }
};