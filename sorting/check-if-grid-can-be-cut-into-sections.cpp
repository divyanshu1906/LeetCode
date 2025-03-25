class Solution {
public:
    bool merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;

        ans.push_back({intervals[0][0], intervals[0][1]});

        for(int i=1; i<n; i++){
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];
            int last = ans.size()-1;
            int prevStart = ans[last][0];
            int prevEnd = ans[last][1];
            if(currStart < prevEnd){
                ans[last][1] = max(ans[last][1], intervals[i][1]);
            }
            else{
                ans.push_back({currStart, currEnd});
            }
        }
        return ans.size()>=3 ? true : false;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int m = rectangles.size();
        vector<vector<int>>xAxis, yAxis;
        for(int i=0; i<m; i++){
            int x1 = rectangles[i][0];
            int y1 = rectangles[i][1];
            int x2 = rectangles[i][2];
            int y2 = rectangles[i][3];
            xAxis.push_back({x1, x2});
            yAxis.push_back({y1, y2});
        }
        return merge(xAxis)==true ? true : merge(yAxis);
    }
};