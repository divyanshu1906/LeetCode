class Solution {
public:
    int BFS(int start, unordered_map<int, vector<int>>adj, vector<bool>visited){
        queue<pair<int, int>>que;
        que.push({start, 0});
        int maxDistance = 0;
        while(!que.empty()){
            auto[curNode, dist] = que.front();
            que.pop();
            for(auto &ngbr : adj[curNode]){
                if(!visited[ngbr]){
                    visited[ngbr] = true;
                    que.push({ngbr, dist+1});
                    maxDistance = max(maxDistance, dist+1);
                }
            }
        }
        return maxDistance;
    }
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        unordered_map<int, vector<int>>adj;
        for(int i=0; i<n; i++){
            int u = i;
            int v = favorite[i];
            adj[v].push_back(u);
        }

        int longestCycleEmplCount = 0;
        int happyCoupleEmpCount = 0;

        vector<bool>visited(n, false);

        for(int i=0; i<n; i++){
            if(!visited[i]){
                unordered_map<int, int>mp;
                int curNode = i;
                int curNodeCount = 0;
                while(!visited[curNode]){
                    visited[curNode]=true;
                    mp[curNode] = curNodeCount;

                    int nextNode = favorite[curNode];
                    curNodeCount += 1;

                    if(mp.count(nextNode)){
                        int cycleLength= curNodeCount-mp[nextNode];
                        longestCycleEmplCount = max(longestCycleEmplCount, cycleLength);

                        if(cycleLength==2){
                            vector<bool>visitedNodes(n, false);
                            visitedNodes[curNode] = true;
                            visitedNodes[nextNode] = true;
                            happyCoupleEmpCount += 2 + BFS(curNode, adj, visitedNodes) + BFS(nextNode, adj, visitedNodes);
                        }
                        break;
                    }
                    curNode = nextNode;
                }
            }
        }
        return max(happyCoupleEmpCount, longestCycleEmplCount);
    }
};