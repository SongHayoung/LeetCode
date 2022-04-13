class Solution {
    vector<long> power;
    int mod = 1e9 + 7;
    string rabinKarp(int len, string& s) {
        if(len == 0) return "";
        long hash = 0;
        unordered_map<long, vector<pair<int, string>>> lookup;
        for(int i = 0; i < len; i++) {
            hash = (hash * 26 + (s[i] - 'a')) % mod;
        }
        lookup[hash].push_back({0, ""});
        for(int i = len; i < s.length(); i++) {
            hash = ((hash - power[len - 1] * (s[i-len] - 'a')) % mod + mod) % mod; //remove
            hash = (hash * 26 + (s[i] - 'a')) % mod;
            string subString = "";
            if(lookup.count(hash)) {
                subString = s.substr(i - len + 1, len);
                for(int j = 0; j < lookup[hash].size(); j++) {
                    if(lookup[hash][j].second == "") {
                        lookup[hash][j].second = s.substr(lookup[hash][j].first, len);
                    }
                    if(lookup[hash][j].second == subString)
                        return subString;
                }
            }
            lookup[hash].push_back({i - len + 1, subString});
        }
        return "";
    }
public:
    string longestDupSubstring(string s) {
        int l = 0, r = s.length();
        power = vector<long>(r, 1);
        for(int i = 1; i < r; i++)
            power[i] = power[i-1] * 26 % mod;
        string res = "";
        while(l <= r) {
            int m = l + (r - l) / 2;
            string cmp;
            if(m == l and l + 1 == r) {
                cmp = rabinKarp(m + 1, s);
                if(cmp.length() == 0)
                    cmp = rabinKarp(m,s);
            } else {
                cmp = rabinKarp(m, s);   
            }
            if(cmp.length() > 0) {
                l = m + 1;
                if(res.length() < cmp.length())
                    res = cmp;
            } else {
                r = m - 1;
            }
        }
        return res;
    }
};