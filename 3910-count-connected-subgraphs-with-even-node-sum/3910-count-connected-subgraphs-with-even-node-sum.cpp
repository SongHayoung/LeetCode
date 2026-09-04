
class Solution {
    bool on[16];
    bool bit(int a, int x) {
        return (a>>x) & 1;
    }
    int dfs(vector<vector<int>>& adj, int u) {
        on[u] = false;
        int res = 1;
        for(auto& v : adj[u]) {
            if(on[v]) res += dfs(adj,v);
        }
        return res;
    }
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size(), res = 0;
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int mask = 1; mask < (1<<n); mask++) {
            int sum = 0, root, cnt = 0;
            unordered_set<int> us;
            for(int i = 0; i < n; i++) {
                if(!bit(mask,i)) on[i] = false;
                else {
                    on[i] = true;
                    sum += nums[i];
                    root = i;
                    cnt++;
                }
            }
            if(sum & 1) continue;
            res += cnt == dfs(adj,root);
        }
        return res;
    }
};
