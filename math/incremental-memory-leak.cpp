class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        vector<int>ans;
        int n = max(memory1, memory2);
        int i=0;
        while(true){
            if(memory1 >= memory2 && memory1 >= i+1){
                memory1 -= i+1;
            }
            else if(memory1 <= memory2 && memory2 >= i+1){
                memory2 -= i+1;
            }
            else{
                return {i+1, memory1, memory2};
            }
            i++;
        }
        return {0};
    }
};