class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26);
        for(auto& ch : s) cnt[ch-'a']++;
        for(int i = 0, l = 0, r = s.length() - 1; i < 26; i++) {
            while(cnt[i] >= 2) {
                cnt[i] -= 2;
                s[l++] = s[r--] = i + 'a';
            }
            if(cnt[i]) s[s.length()/2] = i + 'a';
        }
        return s;
    }
};