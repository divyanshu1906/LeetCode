class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq1;
        for(int num : nums1){
            freq1[num]++;
        }
        vector<int> res;
        for(int nums : nums2){
            if(freq1[nums] >0){
                res.push_back(nums);
                freq1[nums] = 0;
            }
        }
        return res;
    }
};