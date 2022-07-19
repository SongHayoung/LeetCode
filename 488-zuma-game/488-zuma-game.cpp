class Solution {
    unordered_map<char, int> freq;
    unordered_map<string, long long> vis;
    string serialize() {
        string res = "";
        for(auto& [ch, cnt] : freq) {
            res += string(cnt, ch);
        }
        return res;
    }
    string update(string s) {
        int n = s.length(), l = 0, r = 0;
        while(r < n) {
            while(r < n and s[l] == s[r]) r++;
            if(r - l >= 3) {
                return update(s.substr(0,l) + s.substr(r));
            }
            l = r;
        }
        return s;
    }
    long long dfs(string& s) {
        if(s.length() == 0) return 0;
        string key = s + '#' + serialize();
        if(vis.count(key)) return vis[key];
        long long& res = vis[key] = INT_MAX;
        for(auto& [ch, cnt] : freq) {
            if(!cnt) continue;
            for(int i = 0; i < s.length(); i++) {
                if((i and s[i-1] == s[i] and s[i] != ch) or (s[i] == ch)) {
                    cnt--;
                
                    auto ns = update(s.substr(0,i) + string(1,ch) + s.substr(i));
                    res = min(res, 1 + dfs(ns));
                
                    cnt++;
                }
            }
        }
        
        return res;
    }
public:
    int findMinStep(string board, string hand) {
        for(auto& h : hand) freq[h]++;
        long long res = dfs(board);
        return res > hand.length() ? -1 : res;
    }
};