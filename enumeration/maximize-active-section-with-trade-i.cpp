class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int oneCount = 0;
        for(char ch : s){
            if(ch=='1') oneCount++;
        }

        int i=0;
        vector<pair<char, int>>continuousCount;
        while(i<n){
            int ch = s[i];
            int count = 0;
            while(i<n && s[i]==ch){
                count++;
                i++;
            }
            continuousCount.push_back({ch, count});
        }

        int bestGain=0;
        for(int i=0; i+2<continuousCount.size(); i++){
            int currCount = 0;
            if(continuousCount[i].first=='0' && continuousCount[i+1].first=='1' && continuousCount[i+2].first=='0'){
                currCount = continuousCount[i].second + continuousCount[i+2].second;
                bestGain = max(bestGain, currCount);
            }
        }
        return oneCount + bestGain;
    }
};