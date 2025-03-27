class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int maxOccuredElement = nums[0];
        int counter = 1;
        int idx = 1;
        while(idx<n){
            if(nums[idx] != maxOccuredElement) counter--;
            else counter++;
            if(counter==0) {
                maxOccuredElement = nums[idx];
                counter = 1;
            }
            idx++;
        }

        int maxCount = count(nums.begin(), nums.end(), maxOccuredElement);
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