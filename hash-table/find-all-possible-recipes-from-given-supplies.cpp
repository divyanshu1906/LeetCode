class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();

        vector<string>ans;
        unordered_set<string> st(supplies.begin(), supplies.end());
        
        unordered_map<string, vector<int>>adj;
        vector<int>indegree(n);
        for(int i=0; i<n; i++){
            for(string &str : ingredients[i]){
                if(!st.count(str)){
                    adj[str].push_back(i);
                    indegree[i]++;
                }
            }
        }

        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int idx = q.front();
            q.pop();
            string recipe = recipes[idx];
            ans.push_back(recipe);

            for(int &i : adj[recipe]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        return ans;
    }
};