class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minute(timePoints.size());
        for(int i=0; i<timePoints.size(); i++){
            int h = stoi(timePoints[i].substr(0,2));
            int m = stoi(timePoints[i].substr(3));
            minute[i] = h*60+m;
        }
        sort(minute.begin(), minute.end());
        int minDiff = INT_MAX;
        for(int i=0; i<minute.size()-1; ++i){
            minDiff = min(minDiff, minute[i+1]-minute[i]);
        }
        minDiff = min(minDiff, 24*60-minute.back()+minute.front());
        return minDiff;
    }
};