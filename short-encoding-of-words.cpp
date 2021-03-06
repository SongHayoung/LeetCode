class Solution {
    bool isContain(string& longer, string& shorter) {
        for(int i = longer.length() - shorter.length(), j = 0; i < longer.length(); i++, j++) {
            if(longer[i] != shorter[j])
                return false;
        }
        return true;
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        vector<bool> isIncluded(words.size(), false);
        int res = 0;
        for(int i = 0; i < words.size(); i++) {
            if(isIncluded[i]) continue;
            for(int j = i + 1; j < words.size(); j++) {
                if(isIncluded[j]) continue;
                if(isContain(words[i].length() > words[j].length() ? words[i] : words[j], words[i].length() > words[j].length() ? words[j] : words[i])) {
                    isIncluded[words[i].length() > words[j].length() ? j : i] = true;
                }
            }
            if(!isIncluded[i])
                res += words[i].length() + 1;
        }

        return res;
    }
};
