class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq(26);
        for(auto& ch : p) freq[ch-'a']++;
        vector<int> res;
        vector<int> now(26);
        int ok = count(begin(freq), end(freq), 0);
        for(int i = 0; i < s.length(); i++) {
            int x = s[i] - 'a';
            ++now[x];
            if(now[x] == freq[x]) {
                ok++;
            } else if(now[x] - 1 == freq[x]) ok--;
            if(i >= p.length()) {
                int y = s[i-p.length()] - 'a';
                --now[y];
                if(now[y] == freq[y]) ok++;
                else if(now[y] + 1 == freq[y]) ok--;
            }
            if(ok == 26) res.push_back(i-p.length() + 1);
        }
        
        return res;
    }
};