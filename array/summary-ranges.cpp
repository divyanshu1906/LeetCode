class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;
        int left=0, mid=0;
        int right=1;
        while(right < nums.size()){
            if(nums[mid]+1 == nums[right]){
                mid++, right++;
            }
            else{
                if(left==mid){
                    ans.push_back(to_string(nums[left]));
                }
                else{
                    string range = to_string(nums[left])+"->"+to_string(nums[mid]);
                    ans.push_back(range);
                }
                left=right;
                mid=right;
                right++;
            }
        }
         if (left == mid) {
        ans.push_back(to_string(nums[left]));
        } else {
        ans.push_back(to_string(nums[left]) + "->" + to_string(nums[mid]));
        }
        return ans;
    }
};