class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string, int>mpp;
        for(auto n : bannedWords){
            mpp[n]++;
        }
        int count=0;
        for(int i=0; i<message.size(); i++){
            if(mpp.find(message[i]) != mpp.end()) count++;
        }
        if(count>=2) return true;
        return false;
    }
};