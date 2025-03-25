class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
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
            if(currStart <= prevEnd){
                ans[last][0] = min(ans[last][0], intervals[i][0]);
                ans[last][1] = max(ans[last][1], intervals[i][1]);
            }
            else{
                ans.push_back({currStart, currEnd});
            }
        }
        return ans;
    }
};