class Solution {
    void dfs(vector<vector<pair<int,int>>>& adj, int u, long long mask, unordered_map<long long, long long>& freq, unordered_map<long long, long long>& dep, long long& res) {
        if(freq.count(mask)) res += freq[mask];
        if(dep.count(mask)) res += dep[mask] - 1;
        for(int i = 0; i <= 26; i++) {
            if(freq.count(mask ^ (1<<i))) res += freq[mask ^ (1<<i)];
            if(dep.count(mask ^ (1<<i))) res += dep[mask ^ (1<<i)];
        }
        for(auto& [v,m] : adj[u]) {
            dep[mask ^ m] += 1;
            dfs(adj,v,mask ^ m, freq, dep, res);
            dep[mask ^ m] -= 1;
        }
        
        freq[mask] += 1;
    }
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 1; i < parent.size(); i++) {
            adj[parent[i]].push_back({i, 1<<(s[i] - 'a')});
        }
        unordered_map<long long, long long> freq, dep{{0,1}};
        long long res = 0;
        dfs(adj,0,0,freq, dep, res);
        return res;
    }
};