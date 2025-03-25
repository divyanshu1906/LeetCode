class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>arr1(k,0);
        for(int n : arr){
            int rem = n%k;
            if(rem<0){
                rem += k;
            }
            arr1[rem]++;
        }
        if(arr1[0]%2!=0){
            return false;
        }
        for(int i=1; i<=k/2; i++){
            if(arr1[i] != arr1[k-i]){
                return false;
            }
        }
        return true;
    }
};