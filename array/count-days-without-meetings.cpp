class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if(meetings.empty()) return days;
        sort(meetings.begin(), meetings.end());

        int n = meetings.size();
        int freeDays=0;

        int startDay = meetings[0][0], endDay = meetings[0][1];
        for(int i=1; i<n; i++){
            int currStart = meetings[i][0], currEnd = meetings[i][1];

            if(currStart <= endDay){
                endDay = max(endDay, currEnd);
            }
            else{
                freeDays += currStart - endDay-1;
                endDay = currEnd;
            }
        }
        freeDays += startDay-1;
        freeDays += days - endDay;
        return freeDays;
    }
};