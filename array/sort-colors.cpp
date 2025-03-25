class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int first=0, mid=0, last=n-1;
        for(int i=0; i<n; i++){
            if(nums[mid]==0){
                swap(nums[first], nums[mid]);
                first++;
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid], nums[last]);
                last--;
            }
            else{
                mid++;
            }
        }
    }
};