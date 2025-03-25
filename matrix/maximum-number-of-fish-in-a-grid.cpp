class Solution {
public:
    int BFS(int i, int j, vector<vector<int>>&visited, vector<vector<int>> dis, vector<vector<int>>grid, int &count){
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = 1;
        queue<pair<int, int>>q;
        q.push({i, j});
        count += grid[i][j];
        while(!q.empty()){
            pair<int, int> P = q.front();
            q.pop();
            int i_ = P.first;
            int j_ = P.second;
            for(auto &it : dis){
                int row = i_+it[0];
                int col = j_+it[1];
                if(row>=0 && row<n && col>=0 && col<m && !visited[row][col] && grid[row][col]!=0){
                    visited[row][col]=1;
                    q.push({row, col});
                    count += grid[row][col];
                }
            }
        }
        return count;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxFish = 0;
        vector<vector<int>>visited(n, vector<int>(m, 0));
        vector<vector<int>>dis{{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    visited[i][j] = 1;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                int count = 0;
                if(!visited[i][j]){
                    BFS(i, j, visited, dis, grid, count);
                    maxFish = max(maxFish, count);
                }
            }
        }
        return maxFish;
    }
};