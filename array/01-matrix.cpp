class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> ans(m, vector<int>(n, -1)); 
    queue<pair<int, int>> q;  

    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 0) {  
                ans[i][j] = 0;  
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        int i_ = q.front().first;
        int j_ = q.front().second;
        q.pop();

        for (auto &dir : directions) {
            int row = i_ + dir[0];
            int col = j_ + dir[1];

            if (row >= 0 && row < m && col >= 0 && col < n && ans[row][col] == -1) {
                ans[row][col] = ans[i_][j_] + 1;  // Update distance
                q.push({row, col});
            }
        }
    }
    return ans;
}

};