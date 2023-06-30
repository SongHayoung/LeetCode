class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        vector<int> freq(26);
        int res = 0, l = 0, r = 0, n = s.length();
        while(r < n) {
            while(r < n and freq[s[r] - 'a'] == 0) {
                res += (r - l + 1);
                freq[s[r++] - 'a'] += 1;
            }
            while(r < n and freq[s[r] - 'a'] == 1) {
                freq[s[l++]-'a'] -= 1;
            }
        }
        return res;
    }
};