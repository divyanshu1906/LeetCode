class Solution {
public:
    int findLengthOfLCIS(vector<int>& arr) {
        int n = arr.size();
        int i=0, j=0, ans=1;
        while(i<n){
            int res=1;
            for(int j=i+1; j<n; j++){
                if(arr[j] > arr[j-1]) res++;
                else break;
            }
            ans = max(ans, res);
            i++;
        }
        return ans;
    }
};