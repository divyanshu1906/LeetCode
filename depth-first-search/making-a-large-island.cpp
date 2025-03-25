class Solution {
public:
    int n;
    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>&visited, int id){
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j] == 0 || visited[i][j])return 0;
        grid[i][j] = id;
        visited[i][j] = true;
        int size = 1;
        for(vector<int>&dir : direction){
            int i_ = i + dir[0];
            int j_ = j + dir[1];
            size += DFS(grid, i_, j_, visited, id);
        }
        return size;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        int maxArea = 0;
        vector<vector<bool>>visited(n, vector<bool>(n, false));
        int id = 2;
        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int size = DFS(grid, i, j, visited, id);
                    maxArea = max(maxArea, size);
                    mp[id] = size;
                    id++;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    unordered_set<int> uniqueId;
                    for(auto &dir : direction){
                        int i_ = i+dir[0];
                        int j_ = j+dir[1];
                        if(i_>=0 && i_<n && j_>=0 && j_<n && grid[i_][j_]!=0){
                            uniqueId.insert(grid[i_][j_]);
                        }
                    }
                    int overallsize = 1;
                    for(auto & it : uniqueId){
                        overallsize += mp[it];
                    }
                    maxArea = max(maxArea, overallsize);
                }
            }
        }
        return maxArea == 0 ? 1 : maxArea;
    }
};