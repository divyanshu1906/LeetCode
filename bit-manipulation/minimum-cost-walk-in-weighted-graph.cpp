class Solution {
public:

    int find(int x, vector<int>&parent){
        if(x==parent[x]){
            return x;
        }
        return parent[x] = find(parent[x], parent);
    }

    void Union(int x, int y, vector<int>&parent){
        parent[y] = x;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int>parent(n);
        vector<int>cost(n);

        for(int i=0; i<n; i++){
            parent[i] = i;
            cost[i] = -1;
        }

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            int parent_u = find(u, parent);
            int parent_v = find(v, parent);

            if(parent_u != parent_v){
                Union(parent_u, parent_v, parent);
                cost[parent_u] &= cost[parent_v];
            }
            cost[parent_u] &= w;
        }

        vector<int>ans;

        for(auto &q : query){
            int s = q[0];
            int d = q[1];

            int parent_s = find(s, parent);
            int parent_d = find(d, parent);

            if(s==d){
                ans.push_back(0);
            }
            else if(parent_s != parent_d){
                ans.push_back(-1);
            }
            else{
                ans.push_back(cost[parent_s]);
            }
        }
        return ans;
    }
};