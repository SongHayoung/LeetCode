class Solution {
public:
    int possibleStringCount(string word) {
        int res = 0;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i-1]) res++;
        }
        return res + 1;
    }
};