class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        map<int, int> mpp;
        int n = A.size();
        for(int i=0; i<n; i++){
            mpp[A[i]]++;
            mpp[B[i]]++;
            int count = 0;
            for(auto it : mpp){
                if(it.second == 2 ){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};