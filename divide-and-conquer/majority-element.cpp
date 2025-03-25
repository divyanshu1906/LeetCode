class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = nums[0];
        int count = 0, newcount = 0;
        for(int i=0; i<nums.size(); i++){
            if(count == 0){
                count++;
                element = nums[i]; 
            }else if(element == nums[i]){
                count++;
            }else{
                count--;
            }
        }for(int i=0; i<nums.size(); i++){
            if(nums[i]==element){
                newcount++;
            }
        }if(newcount > nums.size()/2){
            return element;
        }else{
            return 0;
        }
    }
};