class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<int>vec(k,0);
        vector<int>ans = {-1000000, 1000000};
        while(true){
        int minEle = INT_MAX;
        int maxEle = INT_MIN;
        int minIndex = 0;
            for(int i=0; i<k; i++){
                int listInd = i;
                int ele = vec[i];
                int element = nums[listInd][ele];
                if(element<minEle){
                    minEle = element;
                    minIndex = i;
                }
                maxEle = max(maxEle, element);
            }
            if(maxEle-minEle < ans[1]-ans[0]){
                ans[0] = minEle;
                ans[1] = maxEle;
            }
            int nextIndex = vec[minIndex]+1;
            if(nextIndex >= nums[minIndex].size()){
                break;
            }
            vec[minIndex] = nextIndex;
        }
        return ans;
    }
};