class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>>q; //{{r, c}, t};
        int time = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
            }
        }
        vector<vector<int>>directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm = q.front().second;
            time = max(time, tm);
            q.pop();
            for(auto &dir : directions){
                int row_ = row + dir[0];
                int col_ = col + dir[1];
                if(row_>=0 &&row_<m && col_>=0 && col_<n && visited[row_][col_]!=2 && grid[row_][col_]==1){
                    q.push({{row_, col_}, tm+1});
                    visited[row_][col_] = 2;
                    grid[row_][col_]=2;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};