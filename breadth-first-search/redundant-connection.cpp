class Solution {
public:
    int UPar(int node, vector<int> &parent){
        if(node==parent[node]) return node;
        return parent[node] = UPar(parent[node], parent);
    }
    bool Union(vector<int>&parent, vector<int>size, int a, int b){
        int ulp_a = UPar(a, parent);
        int ulp_b = UPar(b, parent);
        if(ulp_a == ulp_b)return true;
        if(size[ulp_a] >= size[ulp_b]){
            size[ulp_a] += size[ulp_b];
            parent[ulp_b] = ulp_a;
        }
        else{
            size[ulp_b] += size[ulp_a];
            parent[ulp_a] = ulp_b;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> size(n+1, 1);
        vector<int> parent(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
        for(int i=0; i<n; i++){
            if(Union(parent, size, edges[i][0], edges[i][1])){
                return {edges[i][0], edges[i][1]};
            }
        }
        return {};
    }
};