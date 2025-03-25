class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int change = 0;
        for(int i=0; i<k; i++){
            if(blocks[i]=='W') change++;
        }
        int ans = change;
        int left=0, right = k;
        while(right<n){
            if(blocks[right]=='W')change++;
            if(blocks[left]=='W')change--;
            ans = min(ans,change);
            right++;
            left++;
        }
        return ans;
    }
};