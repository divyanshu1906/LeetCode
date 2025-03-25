class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = 0;
        int n = baskets.size();
        int m = fruits.size();
        vector<bool>visited(n, false);
        for(int i=0; i<m; i++){
            bool flag = false;
            for(int j=0; j<n; j++){
                if(fruits[i]<=baskets[j] && !visited[j]){
                    visited[j] = true;
                    flag = true;
                    break;
                }
            }
            if(!flag) ans++;
        }
        return ans;
    }
};