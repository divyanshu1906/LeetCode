class Solution {
public:
    int n, m;
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>&visited){
        visited[row][col] = 1;
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(auto &dir : directions){
            int row_ = row + dir.first;
            int col_ = col + dir.second;
            if(row_>=0 && row_<m && col_>=0 && col_<n && !visited[row_][col_] && board[row_][col_]=='O'){
                dfs(row_, col_, board, visited);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        m = board.size();
        n = board[0].size();
        vector<vector<int>>visited(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            if(!visited[i][0] && board[i][0]=='O'){
                dfs(i, 0, board, visited);
            }
            if(!visited[i][n-1] && board[i][n-1]=='O'){
                dfs(i, n-1, board, visited);
            }
        }
        for(int j=0; j<n; j++){
            if(!visited[0][j] && board[0][j]=='O'){
                dfs(0, j, board, visited);
            }
            if(!visited[m-1][j] && board[m-1][j]=='O'){
                dfs(m-1, j, board, visited);
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};