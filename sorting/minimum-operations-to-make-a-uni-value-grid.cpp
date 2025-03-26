class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>newArr;
        if(m==1 && n==1) return 0;
        for(int i=0; i<m; i++){
            if(!newArr.empty()){
                int size = newArr.size()-1;
                if(abs(newArr[size]-grid[i][0]) % x != 0)return -1;
            }
            newArr.push_back(grid[i][0]);
            for(int j=1; j<n; j++){
                if(abs(grid[i][j]-grid[i][j-1]) % x != 0) return -1;
                newArr.push_back(grid[i][j]);
            }
        }
        sort(newArr.begin(), newArr.end());
        int s = newArr.size();
        int target = newArr[s/2];
        int operations = 0;
        for(int i=0; i<s; i++){
            operations += (abs(target-newArr[i]))/x;
        }
        return operations;
    }
};