class Solution {
public:
    static bool customSort(const string &a, const string &b){
        int posA = a.find(' ');
        int posB = b.find(' ');

        string subA = a.substr(posA+1);
        string subB = b.substr(posB+1);
        if(subA==subB){
            string prefixA = a.substr(0, posA);
            string prefixB = b.substr(0, posB);
            return prefixA < prefixB;
        }
        return subA<subB;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        int n = logs.size();
        vector<string>letter_log, digit_log;
        for(int i=0; i<n; i++){
            string str = logs[i];
            int j = 0;
            while(str[j] != ' '){
                j++;
            }
            j++;
            if(isdigit(str[j])){
                digit_log.push_back(str);
            }
            else if(islower(str[j])){
                letter_log.push_back(str);
            }
        }
        sort(letter_log.begin(), letter_log.end(), customSort);
        for(int i=0; i<digit_log.size(); i++){
            letter_log.push_back(digit_log[i]);
        }
        return letter_log;
    }
};