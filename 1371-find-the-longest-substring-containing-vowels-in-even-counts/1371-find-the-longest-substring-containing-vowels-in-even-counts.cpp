class Solution {
public:
    int findTheLongestSubstring(string s) {
        auto bit = [](char ch) {
            if(ch == 'a') return 0;
            if(ch == 'e') return 1;
            if(ch == 'i') return 2;
            if(ch == 'o') return 3;
            if(ch == 'u') return 4;
            return -1;
        };
        unordered_map<int, int> mp;
        mp[0] = -1;
        int res = 0;
        for(int i = 0, mask = 0; i < s.length(); i++) {
            int bi = bit(s[i]);
            if(bi != -1) mask ^= (1<<bi);
            if(mp.count(mask)) {
                res = max(res, i - mp[mask]);
            } else mp[mask] = i;
        }
        return res;
    }
};