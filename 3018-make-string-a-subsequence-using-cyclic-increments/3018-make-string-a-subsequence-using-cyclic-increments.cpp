class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int j = 0;
        for(int i = 0; i < str1.size(); i++) {
            if(j == str2.size()) return true;
            if(str1[i] == str2[j] or (str1[i] + 1 - 'a') % 26 + 'a' == str2[j]) j += 1;
        }
        if(j == str2.size()) return true;
        return false;
    }
};