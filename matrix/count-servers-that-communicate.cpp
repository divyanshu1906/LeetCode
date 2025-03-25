class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            pair<int, int> front = q.front();
            q.pop();
            int i = front.first;
            int j = front.second;

            int count = 0; 
            for (int i_ = 0; i_ < n; i_++) {
                if(i==i_)continue;
                if (grid[i_][j] == 1) {
                    count++;
                }
            }
            for (int j_ = 0; j_ < m; j_++) {
                if(j==j_)continue;
                if (grid[i][j_] == 1) {
                    count++;
                }
            }
            if (count > 0) {
                ans++;
            }
        }
        return ans;
    }
};
