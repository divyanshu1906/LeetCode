class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }
    
        for (int i = 0; i < s.size() - 1; i++) {
            char first = s[i], second = s[i + 1];
    
            if (first != second) { 
                int count1 = freq[first];
                int count2 = freq[second];
    
                if (count1 == first - '0' && count2 == second - '0') {
                    return string(1, first) + string(1, second);
                }
            }
        }
    
        return "";
    }
};