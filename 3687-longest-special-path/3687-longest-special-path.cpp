struct Seg{
    int mi,ma,sum;
    Seg *left, *right;
    Seg(int l, int r) : mi(l), ma(r), sum(0), left(nullptr), right(nullptr) {
        if(l^r) {
            int m = l + (r - l) / 2;
            left = new Seg(l,m);
            right = new Seg(m+1,r);
        }
    }
    void update(int n, int x) {
        if(mi <= n and n <= ma) {
            if(mi == ma) {
                sum = x;
            } else {
                left->update(n,x);
                right->update(n,x);
                sum = left->sum + right->sum;
            }
        }
    }
    int query(int l, int r) {
        if(l <= mi and ma <= r) return sum;
        if(l > ma or r < mi) return 0;
        return left->query(l,r) + right->query(l,r);
    }
};
class Solution {
    vector<vector<pair<int,int>>> adj;
    Seg* seg;
    unordered_map<int,vector<int>> deps;
    void dfs(int u, int par, int dep, int hi, vector<int>& res, vector<int>& A) {
        if(deps[A[u]].size()) hi = max(hi, deps[A[u]].back() + 1);
        deps[A[u]].push_back(dep);
        int w = seg->query(hi,dep);
        int l = dep - hi + 1;
        if(res[0] < w) res = {w,l};
        else if(res[0] == w) res[1] = min(res[1],l);
        
        for(auto& [v,w] : adj[u]) {
            if(v == par) continue;
            seg->update(dep,w);
            dfs(v,u,dep+1,hi,res,A);
        }
        seg->update(dep,0);
        deps[A[u]].pop_back();
    }
public:
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        seg = new Seg(0, edges.size() + 1);
        deps = {};
        adj = vector<vector<pair<int,int>>>(edges.size() + 1);
        for(auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> res{0,1};
        dfs(0,-1,0,0,res,nums);
        return res;
    }
};