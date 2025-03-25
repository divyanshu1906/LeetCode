class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int i=0, j=0;
        int swapCount = 0, oneCount = 0, minAns = n;;
        for(int k=0; k<n; k++){
            if(nums[k]==1) oneCount++;
        }
        if(oneCount==0) return 0;
        while(j<n*2){
            if(nums[j%n]==0) swapCount++;
            while(j-i+1 > oneCount){
                if(nums[i%n]==0){
                    swapCount--;
                    minAns = min(minAns, swapCount);
                }
                i++;
            }
            j++;
        }
        return minAns==n ? 0 : minAns;
    }
};