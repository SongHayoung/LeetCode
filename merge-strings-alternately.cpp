class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        stringstream ss;
        int len = max(word1.length(), word2.length());
        for(int i = 0; i < len; i++) {
            if(i < word1.length())
                ss<<word1[i];
            if(i < word2.length())
                ss<<word2[i];
        }
        
        return ss.str();
    }
};
