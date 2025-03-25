class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> adj;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int connectedCompleteComponents = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> component;
                component.push_back(i);
                visited[i] = true;

                for (int j = 0; j < component.size(); j++) {
                    int node = component[j];
                    for (int neighbor : adj[node]) {
                        if (!visited[neighbor]) {
                            visited[neighbor] = true;
                            component.push_back(neighbor);
                        }
                    }
                }

                int size = component.size();

                bool isComplete = true;
                for (int node : component) {
                    if (adj[node].size() != size - 1) {
                        isComplete = false;
                        break;
                    }
                }

                if (isComplete) connectedCompleteComponents++;
            }
        }
        return connectedCompleteComponents;
    }
};