class Solution {
    long long dfs(vector<vector<int>>& adj, unordered_map<int,int>& freq, vector<int>& nums, int u, int par) {
        long long res = freq[nums[u]];
        freq[nums[u]]++;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            res += dfs(adj,freq,nums,v,u);
        }
        freq[nums[u]]--;
        return res;
    }
public:
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        vector<int> pows;
        for(int i = 2; i * i <= 1e5; i++) {
            pows.push_back(i * i);
        }
        for(auto& n : nums) {
            for(auto& p : pows) {
                if(n < p) break;
                while(n % p == 0) n /= p;
            }
        }
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_map<int,int> freq;
        return dfs(adj,freq,nums,0,-1);
    }
};