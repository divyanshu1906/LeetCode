class Solution {
public:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        vector<int>nextConsonant(n);
        int nextConst = n;
        for(int i=n-1; i>=0; i--){
            nextConsonant[i] = nextConst;
            if(!isVowel(word[i])){
                nextConst = i;
            }
        }

        int l=0,r=0, consonant=0;
        long long count = 0;
        unordered_map<char, int>mp;
        
        while(r<n){
            char ch = word[r];
            if(isVowel(ch)){
                mp[ch]++;
            }
            else consonant++;

            while(l<n && consonant>k){
                char ch = word[l];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch]==0){
                        mp.erase(ch);
                    }
                }else{
                    consonant--;
                }
                l++;
            }

            while(l<n && mp.size()==5 && consonant==k){
                int idx = nextConsonant[r];
                count += idx-r;
                char ch = word[l];
                if(isVowel(ch)){
                    mp[ch]--;
                    if(mp[ch]==0){
                        mp.erase(ch);
                    }
                }else{
                    consonant--;
                }
                l++;
            }
            r++;
        }
        return count;
    }
};