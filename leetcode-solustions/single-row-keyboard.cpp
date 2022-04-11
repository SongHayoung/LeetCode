class Solution {
public:
    int calculateTime(string keyboard, string word) {
        map<char, int> keyIndex;
        for(int i = 0; i < keyboard.length(); ++i) {
            keyIndex[keyboard[i]] = i;
        }
        
        int finger = 0;
        int res = 0;
        for(int i = 0; i < word.length(); ++i) {
            res += abs(keyIndex[word[i]] - finger);
            finger = keyIndex[word[i]];
        }

        return res;
    }
};
