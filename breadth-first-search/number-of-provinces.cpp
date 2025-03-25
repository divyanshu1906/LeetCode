class Solution {
public:
    void bfs(int node, vector<bool>&visited, unordered_map<int, vector<int>>&adj){
        visited[node] = true;
        for(int &ngbr : adj[node]){
            if(!visited[ngbr]){
                bfs(ngbr, visited, adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>>adj;
        int n = isConnected.size();
        for(int i = 0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j)continue;
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        vector<bool>visited(n, false);
        int provinces = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                bfs(i, visited, adj);
                provinces++;
            }
        } 
        return provinces;
    }
};