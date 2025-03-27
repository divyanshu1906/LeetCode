class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int maxOccuredElement = nums[0];
        int count = 1;
        int idx = 1;
        while(idx<n){
            if(nums[idx] != maxOccuredElement) count--;
            else count++;
            if(count==0) {
                maxOccuredElement = nums[idx];
                count = 1;
            }
            idx++;
        }
        int maxCount=0;
        for(int i=0; i<n; i++){
            if(nums[i]==maxOccuredElement) maxCount++;
        }
        int half = ceil(n/2.0);

        if(maxCount>half){
            int currCount = 0;
            for(int i=0; i<n; i++){
                if(nums[i]==maxOccuredElement){
                    maxCount--;
                    currCount++;
                    if((currCount*2)>i+1) return i;
                }
            }
        }
        return -1;
    }
};