class Solution {
public:
    int maximumLength(string s) {
        unordered_map<int, unordered_map<int, int>> mp;
        int l = 0, r = 0, n = s.length();
        int res = -1;
        while(r < n) {
            while(r < n and s[l] == s[r]) r++;
            int len = r - l;
            for(int i = 1; i <= 3 and len > 0; i++, len--) {
                mp[s[l]-'a'][len] += i;
                if(mp[s[l]-'a'][len] >= 3) res = max(res, len);
            }
            l = r;
        }
        return res;
    }
};
