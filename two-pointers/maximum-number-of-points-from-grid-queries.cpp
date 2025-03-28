class Solution {
public:
    int n,m;
    vector<vector<int>>directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(int i, int j, vector<vector<int>>& grid, int &count, vector<vector<bool>>&visited, int query){
        visited[i][j] = true;
        queue<pair<int, int>>q;
        q.push({i, j});
        while(!q.empty()){
            int i_ = q.front().first;
            int j_ = q.front().second;
            q.pop();
            count++;
            for(auto &dir : directions){
                int row = i_ + dir[0];
                int col = j_ + dir[1];
                if(row>=0 && row<m && col>=0 && col<n && !visited[row][col] && query>grid[row][col]){
                    q.push({row, col});
                    visited[row][col] = true;
                }
            }
        }
    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        m = grid.size(), n = grid[0].size();
        int k = queries.size();
        vector<int>ans(k, 0);
        for(int i=0; i<k; i++){
            int count = 0;
            if(queries[i]>grid[0][0]){
                vector<vector<bool>>visited(m, vector<bool>(n, false));
                dfs(0, 0, grid, count, visited, queries[i]);
            }
            ans[i] = count;
        }
        return ans;
    }
};