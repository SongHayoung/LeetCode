class Solution {
public:
    int maximumLengthSubstring(string s) {
        int res = 0, l = 0, r = 0, n = s.length();
        vector<int> freq(26);
        while(r < n) {
            while(r < n and freq[s[r]-'a'] < 2) {
                freq[s[r]-'a']++;
                r++;
            }
            res = max(res, r - l);
            while(r < n and freq[s[r]-'a'] == 2) {
                freq[s[l]-'a']--;
                l++;
            }
        }
        return res;
    }
};