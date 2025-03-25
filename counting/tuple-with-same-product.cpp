class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tupleCount = 0;
        unordered_map<int, int>mpp;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int num = nums[i]*nums[j];
                mpp[num]++;
            }
        }
        for(auto &it : mpp){
            int freq = it.second;
            int ans = 0;
            ans =(freq * (freq-1))/2;
            tupleCount += ans*8;
        }
        return tupleCount;
    }
};