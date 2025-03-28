class Solution {
public:
    int n,m;
    vector<vector<int>>directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>> &grid, int &count, vector<vector<bool>>&visited, int queryValue, vector<pair<int, int>> &visitFrom){
        queue<pair<int, int>>q;
        for(auto &it : visitFrom){
            q.push(it);
        }

        while(!q.empty()){
            int size = q.size();
            vector<pair<int, int>>lastGreaterElement;

            while(size--){
                int i_ = q.front().first;
                int j_ = q.front().second;
                lastGreaterElement.push_back({i_,j_});
                q.pop();

                if(queryValue > grid[i_][j_]){
                    if (!visited[i_][j_]) {
                        visited[i_][j_] = true;
                        count++;
                    }
                    for(auto &dir : directions){
                        int row = dir[0]+i_;
                        int col = dir[1]+j_;

                        if(row>=0 && row<m && col>=0 && col<n && !visited[row][col]){
                            if (grid[row][col] < queryValue) {
                                q.push({row, col});
                            } 
                            else {
                                lastGreaterElement.push_back({row, col});
                            }
                        }
                    }
                }
            }
            visitFrom = lastGreaterElement;
        }
    }
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        m = grid.size(), n = grid[0].size();
        int k = queries.size();
        unordered_map<int, int>mpp;
        for(int i=0; i<k; i++){
            mpp[queries[i]] = i;
        }
        sort(queries.begin(), queries.end());
        vector<int>ans(k, 0), finalAns(k,0);
        vector<pair<int, int>>visitFrom;
        visitFrom.push_back({0,0});
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        for(int i=0; i<k; i++){
            int count = 0;
            dfs(grid, count, visited, queries[i], visitFrom);
            if(i>0)ans[i] = ans[i-1]+count;
            else ans[i] = count;
        }
        for(int i=0; i<k; i++){
            int idx = mpp[queries[i]];
            finalAns[idx] = ans[i];
        }
        return finalAns;
    }
};