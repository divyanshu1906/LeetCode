class DSU{
public:
    vector<int>parent, size;

    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++) parent[i] = i;
    }

    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y){
        int parentX = find(x);
        int parentY = find(y);

        if(parentX != parentY){
            if(size[parentX] < size[parentY]){
                parent[parentX] = parentY;
                size[parentY] += size[parentX];
            }
            else{
                parent[parentY] = parentX;
                size[parentX] += size[parentY];
            }
        }
    }

};

class Solution {
public:
    int intersect(const vector<int>&a, const vector<int>&b, int k){
        unordered_set<int> setA;
        for (int num : a) setA.insert(num); 

        int count = 0;
        for(int num : b){
            if(setA.count(num)){
                count++;
                setA.erase(num);
                if(count>=k)return count;
            }
        }
        return count;
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        DSU dsu(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(intersect(properties[i], properties[j], k) >= k){
                    dsu.unite(i,j);
                }
            }
        }
        
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.find(i) == i) components++;
        }

        return components;
    }
};