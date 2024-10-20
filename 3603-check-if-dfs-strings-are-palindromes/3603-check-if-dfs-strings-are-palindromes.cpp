class Solution {
    vector<vector<int>> adj;
    vector<int> size, ord;
    int dfs(int u, string& s, string& ss) {
        size[u]++;
        for(auto& v : adj[u]) {
            size[u] += dfs(v,s,ss);
        }
        ss.push_back(s[u]);
        ss.push_back('#');
        ord.push_back(u);
        return size[u];
    }
    vector<int> manacher(string& s) {
        vector<int> dp(s.length());
        for(int i = 0, l = 0, r = -1; i < s.length(); i++) {
            dp[i] = max(0, min(r - i, r + l - i >= 0 ? dp[r + l - i] : -1));
            while(i + dp[i] < s.length() and i - dp[i] >= 0 and s[i-dp[i]] == s[i+dp[i]]) dp[i]++;
            if(r < i + dp[i]) {
                r = i + dp[i];
                l = i - dp[i];
            }
        }
        return dp;
    }
public:
    vector<bool> findAnswer(vector<int>& parent, string& s) {
        vector<bool> res(s.length());
        size = vector<int>(s.length());
        ord = {};
        adj = vector<vector<int>>(s.length());
        for(int u = 1; u < parent.size(); u++) {
            adj[parent[u]].push_back(u);
        }
        
        string S = "#";
        dfs(0,s,S);
        vector<int> dp = manacher(S);
        for(int i = 0; i < s.length(); i++) {
            int u = ord[i], r = i * 2 + 1, l = r - size[u] * 2 + 2;
            int m = l + (r - l) / 2;
            res[u] = (dp[m] * 2) - 1 >= (r - l + 1);
        }
        return res;
    }
};