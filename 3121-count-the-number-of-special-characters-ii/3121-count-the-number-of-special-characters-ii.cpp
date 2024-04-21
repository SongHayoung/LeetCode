class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lo(26,-1), hi(26,-1);
        for(int i = 0; i < word.size(); i++) {
            if(islower(word[i])) {
                lo[word[i]-'a'] = i;
            }
        }
        for(int i = word.size() - 1; i >= 0; i--) {
            if(isupper(word[i])) {
                hi[word[i]-'A'] = i;
            }
        }
        int res = 0;
        for(int i = 0; i < 26; i++) {
            if(lo[i] == -1 or hi[i] == -1) continue;
            if(lo[i] > hi[i]) continue;
            res++;
        }
        return res;
    }
};