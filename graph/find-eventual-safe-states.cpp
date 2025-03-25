class Solution {
public:
    bool isCycle(vector<vector<int>>&mat, int u, vector<bool>&visited, vector<bool>&isRecursion){
        visited[u]=true;
        isRecursion[u]=true;
        for(int &v : mat[u]){
            if(visited[v]==false && isCycle(mat, v, visited, isRecursion)){
                return true;
            }
            else if(isRecursion[v]==true) return true;
        }
        isRecursion[u] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool>visited(n, false);
        vector<bool>isRecursion(n, false);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                isCycle(graph, i, visited, isRecursion);
            }
        }
        vector<int>safeNode;
        for(int i=0; i<n; i++){
            if(isRecursion[i]==false){
                safeNode.push_back(i);
            }
        }
        return safeNode;
    }
};
