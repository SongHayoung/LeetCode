class Solution {
public:
    bool detectCapitalUse(string word) {
        int up = 0;
        for(auto w : word) if(isupper(w)) up += 1;
        if(up == word.size()) return true;
        if(up == 0) return true;
        if(up == 1 and isupper(word[0])) return true;
        return false;
    }
};