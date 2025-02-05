class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff = 0, counter[26]{0,};
        for(int i = 0; i < s1.length() and diff <= 2; i++) {
            if(s1[i] != s2[i]) {
                diff++;
                counter[s1[i]-'a']++;            
                counter[s2[i]-'a']--;
            }
        }
        if(diff == 0) return true;
        if(diff == 2) {
            for(int i = 0; i < 26; i++)
                if(counter[i]) return false;
            return true;
        }
        return false;
    }
};