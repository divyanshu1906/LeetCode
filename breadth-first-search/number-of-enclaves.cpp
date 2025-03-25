class Solution {
public:
    int n, m;
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited){
        vector<pair<int, int>>directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        visited[i][j] = 1;
        for(auto &dir : directions){
            int i_ = i + dir.first;
            int j_ = j + dir.second;
            if(i_>=0 && i_<m && j_>=0 && j_<n && !visited[i_][j_] && grid[i_][j_]==1){
                dfs(i_, j_, grid, visited);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>>visited(m, vector<int>(n, 0));
        int enclaves = 0;
        for(int j=0; j<n; j++){
            if(grid[0][j]==1 && !visited[0][j]){
                dfs(0, j, grid, visited);
            }
            if(grid[m-1][j]==1 && !visited[m-1][j]){
                dfs(m-1, j, grid, visited);
            }
        }
        for(int i=0; i<m; i++){
            if(grid[i][0]==1 && !visited[i][0]){
                dfs(i, 0, grid, visited);
            }
            if(grid[i][n-1]==1 && !visited[i][n-1]){
                dfs(i, n-1, grid, visited);
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && visited[i][j] == 0){
                    enclaves++;
                }
            }
        }
        return enclaves;
    }
};