class Solution {
public:
    bool biPartite(int curr, vector<int>&colors, unordered_map<int, vector<int>>adj, int color){
        colors[curr] = color;
        for(int &ngbr : adj[curr]){
            if(colors[curr] == colors[ngbr]) return false;
            if(colors[ngbr]==-1){
                if(biPartite(ngbr, colors, adj, 1-color)==false) return false;
            }
        }
        return true;
    }

    int bfs(unordered_map<int, vector<int>>&adj, int currNode, int n ){
        queue<int>q;
        q.push(currNode);
        vector<bool>visited(n, false);
        visited[currNode] = true;
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int node = q.front();
                q.pop();
                for(int &ngbr : adj[node]){
                    if(visited[ngbr]){
                        continue;
                    }
                    q.push(ngbr);
                    visited[ngbr] = true;
                }
            }
            level++;
        }
        return level;
    }

    int getMaxFromEachComp(unordered_map<int, vector<int>> &adj, int currNode, vector<bool> &visited, vector<int>&level){
        int maxGrp = level[currNode];
        visited[currNode] = true;

        for(int &ngbr : adj[currNode]){
            if(!visited[ngbr]){
                maxGrp = max(maxGrp, getMaxFromEachComp(adj, ngbr, visited, level));
            }
        }
        return maxGrp;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>adj;
        for(auto &it : edges){
            int u = it[0]-1;
            int v = it[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>colors(n, -1);
        for(int node=0; node<n; node++){
            if(colors[node]==-1){
                if(biPartite(node, colors, adj, 1) == false){
                    return -1;
                }
            }
        }
        vector<int>level(n, 0);
        for(int i=0; i<n; i++){
            level[i] = bfs(adj, i, n);
        }
        int maxGroup = 0;
        vector<bool>visited(n, false);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                maxGroup += getMaxFromEachComp(adj, i, visited, level);
            }
        }
        return maxGroup;
    }
};