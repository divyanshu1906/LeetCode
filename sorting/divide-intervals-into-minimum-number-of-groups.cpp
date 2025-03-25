class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>startTime, endTime;
        for(const auto& inte : intervals){
            startTime.push_back(inte[0]);
            endTime.push_back(inte[1]);
        }
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
        int group=0, end_ptr=0;
        for(int s : startTime){
            if(s>endTime[end_ptr]){
                end_ptr++;
            }
            else{
                group++;
            }
        }
        return group;
    }
};