class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>newArr;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                newArr.push_back(grid[i][j]);
            }
        }

        sort(newArr.begin(), newArr.end());

        int s = newArr.size();
        int target = newArr[s/2];
        int operations = 0;

        for(int &num : newArr){
            if(num%x != target%x) return -1;
            operations += abs(target-num)/x;
        }

        return operations;
    }
};