class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        unordered_map<int, pair<int, int>>mpp;
        int val=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    mpp[val] = {i, j};
                    val++;
                }
            }
        }
        for(auto it : mpp){
            int i_ = it.second.first;
            int j_ = it.second.second;
            for(int i=0; i<n; i++){
                matrix[i][j_] = 0;
            }
            for(int j=0; j<m; j++){
                matrix[i_][j] = 0;
            }
        }
    }
};