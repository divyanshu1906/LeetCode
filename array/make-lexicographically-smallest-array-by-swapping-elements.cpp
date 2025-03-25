class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> vec = nums;
        sort(begin(vec), end(vec));

        int groupNumber = 0;
        unordered_map<int, int> numToGroup;
        numToGroup[vec[0]] = groupNumber;

        unordered_map<int, list<int>> groupToList;
        groupToList[groupNumber].push_back(vec[0]);
        for(int i=1; i<n; i++){
            if(abs(vec[i]-vec[i-1]) > limit){
                groupNumber++;
            }
            groupToList[groupNumber].push_back(vec[i]);
            numToGroup[vec[i]] = groupNumber;
        }
        for(int i=0; i<n; i++){
            int group = numToGroup[nums[i]];
            nums[i] = *(groupToList[group].begin());
            groupToList[group].pop_front();
        }
        return nums;
    }
};