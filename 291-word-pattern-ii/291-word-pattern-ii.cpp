class Solution {
    void comb(int n, unordered_map<char,int>& freq, vector<unordered_map<char, int>>& res, unordered_map<char,int> now, vector<char>& ps, int p = 0) {
        if(p == freq.size()) {
            if(n == 0) res.push_back(now);
            return;
        }
        if(n <= 0) {
            return;
        }
        auto ch = ps[p];
        int count = freq[ch];
        for(int i = 1; i <= n / count; i++) {
            now[ch] = i;
            comb(n - count * i, freq, res, now, ps, p + 1);
            now[ch] = 0;
        }
    }
    bool helper(string& p, unordered_map<char,int>& len, string& s) {
        unordered_map<char, string> mp;
        
        for(int i = 0, j = 0; i < p.length(); i++) {
            int l = len[p[i]];
            string sub = s.substr(j,l);
            j += l;
            if(mp.count(p[i])) {
                if(mp[p[i]] != sub) return false;
            } else mp[p[i]] = sub;
        }
        unordered_set<string> us;
        for(auto& [_, sub] : mp) us.insert(sub);
        return us.size() == mp.size();
    }
public:
    bool wordPatternMatch(string pattern, string s) {
        unordered_map<char, int> freq;
        for(auto& p : pattern) freq[p]++;
        vector<unordered_map<char, int>> combs;
        vector<char> ps;
        for(auto& [k, _] : freq) ps.push_back(k);
        comb(s.length(), freq, combs, unordered_map<char,int>() = {}, ps);
        
        for(auto& mp : combs) {
            if(helper(pattern, mp, s))
                return true;
        }
        return false;
    }
};