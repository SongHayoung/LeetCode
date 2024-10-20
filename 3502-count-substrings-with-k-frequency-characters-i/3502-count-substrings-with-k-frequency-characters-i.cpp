class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int res = 0, prv = -1;
        vector<int> cnt(26);
        for(int l = 0, r = 0; r < s.length(); r++) {
            if(++cnt[s[r]-'a'] == k) {
                while(s[l] != s[r]) --cnt[s[l++]-'a'];
                res += (l - prv) * (s.length() - r);
                prv = l;
                while(cnt[s[r]-'a'] == k) --cnt[s[l++]-'a'];
            }
        }
        return res;
    }
};