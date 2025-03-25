class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)return image;
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int startingColor = image[sr][sc];
        queue<pair<int, int>>q;
        q.push({sr, sc});
        image[sr][sc] = color;
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(auto &dir : directions){
                int i_ = i + dir[0];
                int j_ = j + dir[1];
                if(i_>=0 && i_<n && j_>=0 && j_<m && image[i_][j_]==startingColor){
                    image[i_][j_] = color;
                    q.push({i_, j_});
                }
            }
        }
        return image;
    }
};