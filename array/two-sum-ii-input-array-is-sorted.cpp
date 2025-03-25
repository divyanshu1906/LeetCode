class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mpp;
        vector<int> ans;
        for(int i=0; i<numbers.size(); i++){
            mpp[numbers[i]] = i+1;
        }
        for(int i=0; i<numbers.size(); i++){
            int x = target - numbers[i];
            if(mpp.find(x) != mpp.end()){
                ans.push_back(i+1);
                ans.push_back(mpp[x]);
                break;
            }
        }
        return ans;
    }
};