class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        vector<string>S1,S2;
        stringstream ss1(s1);
        stringstream ss2(s2);
        string word1, word2;
        while(ss1>>word1){
            S1.push_back(word1);
        }
        while(ss2>>word2){
            S2.push_back(word2);
        }
        unordered_map<string, int>mpp;
        for(const auto& n : S1){
            mpp[n]++;
        }
        for(const auto& m : S2){
            mpp[m]++;
        }
        for(const auto& n : mpp){
            if(n.second == 1){
                ans.push_back(n.first);
            }
        }
        return ans;
    }
};