class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& task) {
        sort(task.begin(), task.end());
        sort(processorTime.begin(), processorTime.end());
        int n = processorTime.size();
        int m = task.size();
        int k = 0;
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            int currAns = INT_MIN;
            int idx = m-k-1;
            for(int j=idx; j>=max(0,idx-4); j--){
                currAns = max(currAns, (processorTime[i]+task[j]));
            }
            k+=4;
            ans = max(ans, currAns);
        }
        return ans;
    }
};