class Solution {
    int mod = 1e9 + 7;
    pair<vector<long long>, vector<long long>> dfs(vector<vector<int>>& adj, int u, vector<int>& A, int k) {
        vector<long long> yes(k), no(k);
        yes[A[u]%k] = 1;

        for(auto& v : adj[u]) {
            auto [vyes, vno] = dfs(adj,v,A,k);
            {
                vector<long long> dpp = no;
                for(int i = 0; i < k; i++) {
                    dpp[i] = (dpp[i] + vyes[i] + vno[i]) % mod;
                    if(!no[i]) continue;
                    for(int j = 0; j < k; j++) {
                        dpp[(j + i) % k] = (dpp[(j + i) % k] + no[i] * (vyes[j] + vno[j]) % mod) % mod;
                    }
                }
                swap(dpp, no);
            }
            {
                vector<long long> dpp = yes;
                for(int i = 0; i < k; i++) {
                    if(!yes[i]) continue;
                    for(int j = 0; j < k; j++) {
                        dpp[(j + i) % k] = (dpp[(j + i) % k] + yes[i] * vno[j] % mod) % mod;
                    }
                }
                swap(dpp,yes);
            }
        }
        return {yes, no};
    }
public:
    int countValidSubsets(vector<int>& parent, vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++) adj[parent[i]].push_back(i);
        auto [a,b] = dfs(adj,0,nums,k);
        return (a[0] + b[0]) % mod;
    }
};