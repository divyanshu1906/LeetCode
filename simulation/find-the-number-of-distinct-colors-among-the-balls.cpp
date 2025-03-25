class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        unordered_map<int, int>ballMap;
        unordered_map<int, int>colorMap;
        vector<int>result(n);
        for(int i=0; i<n; i++){
            int ball = queries[i][0];
            int color = queries[i][1];
            if(ballMap.count(ball)){
                int prevColor = ballMap[ball];
                colorMap[prevColor]--;
                if(colorMap[prevColor]==0){
                    colorMap.erase(prevColor);
                }
            }
            ballMap[ball] = color;
            colorMap[color]++;
            result[i] = colorMap.size();
        }
        return result;
    }
};