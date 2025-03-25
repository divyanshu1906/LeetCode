class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>mpp;
        string ans;
        for(char n : s){
            mpp[n]++;
        }
        vector<pair<char, int>> freq(mpp.begin(), mpp.end());
        sort(freq.begin(), freq.end(), [](const auto &a, const auto &b){
            return a.second > b.second;
        });
        for(const auto &n : freq){
            ans += string(n.second, n.first);
        }
        return ans;
    }
};