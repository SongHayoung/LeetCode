class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        for(; i < word.size() and j < abbr.size();) {
            if(isdigit(abbr[j])) {
                if(abbr[j] == '0') return false;
                int num = 0;
                while(j < abbr.size() and isdigit(abbr[j])) {
                    num = num * 10 + abbr[j++] - '0';
                    if(i + num > word.size()) return false;
                }
                i += num;
            } else {
                if(word[i] != abbr[j]) return false;
                i++,j++;
            }
        }
        return i == word.size() and j == abbr.size();
    }
};