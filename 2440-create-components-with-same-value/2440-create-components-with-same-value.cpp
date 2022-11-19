class Solution {
    int p[20202], lvl[20202];
    void dfs(int u, int par, int dep, vector<vector<int>>& adj, vector<int>& leaf) {
        bool l = true;
        p[u] = par;
        lvl[u] = dep;
        for(auto v : adj[u]) {
            if(v == par) continue;
            l = false;
            dfs(v,u,dep + 1, adj,leaf);
        }
        if(l) leaf.push_back(u);
    }
    int helper(vector<int>& leaf, vector<int>& A, int k) {
        int res = 0;
        priority_queue<pair<int, int>> q;
        unordered_set<int> inc;
        for(auto l : leaf) q.push({lvl[l], l});
        unordered_map<int, int> mp;
        while(q.size()) {
            auto [_, u] = q.top(); q.pop();
            mp[u] += A[u];
            if(mp[u] == k) mp[u] = 0, res += 1;
            else if(mp[u] > k) return 0;
            if(!inc.count(p[u]) and p[u] >= 0) {
                inc.insert(p[u]);
                q.push({lvl[p[u]], p[u]});
            }
            mp[p[u]] += mp[u];
        }
        if(mp[0]) return 0;
        return res - 1;
    }
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        vector<int> leaf;
        vector<vector<int>> adj(nums.size());
        for(auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1,0,adj,leaf);
        unordered_set<int> cand;
        for(auto l : leaf) {
            int sum = nums[l];
            cand.insert(sum);
            while(l) {
                l = p[l];
                sum += nums[l];
                cand.insert(sum);
            }
        }
        int res = 0, ma = *max_element(begin(nums), end(nums)), sum = accumulate(begin(nums), end(nums), 0);
        for(auto c : cand) {
            if(c < ma) continue;
            if(sum % c) continue;
            res = max(res, helper(leaf, nums, c));
        }
        return res;
    }
};