class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        unordered_map<int, int>mpp;
        int ans=INT_MAX;
        for(int i=0; i<arr.size(); i++){
            mpp[arr[i]] = i;
        }
        for(int i=0; i<n; i++){
            int ind = 0;
            for(int j=0; j<m; j++){
                ind = max(ind, mpp[mat[i][j]]);
            }
            ans = min(ans, ind);
        }
        for(int j=0; j<m; j++){
            int ind = 0;
            for(int i=0; i<n; i++){
                ind = max(ind, mpp[mat[i][j]]);
            }
            ans = min(ans, ind);
        }
        return ans;
    }
};