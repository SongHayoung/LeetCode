#define all(a) begin(a),end(a)
class Solution {
    unordered_set<int> us[1000];
    unordered_set<int> lazy;
    unordered_set<int> rst[1000];
    int uf[1000];
    int N;
    int find(int u) {
        return uf[u] == u ? u : uf[u] = find(uf[u]);
    }
    
    void merge(int u, int v) {
        int pu = find(u), pv = find(v);
        uf[pu] = uf[pv] = min(pu, pv);
        lazy.insert(min(pu,pv));
    }
    
    unordered_set<int> group(int u) {
        if(lazy.count(u)) {
            for(int i = 0; i < N; i++)
                if(find(i) == u) {
                    us[u].insert(all(us[i]));
                    rst[u].insert(all(rst[i]));
                }
            lazy.erase(u);
        }
        return us[u];
    }
    
    bool deny(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return true;
        auto gu = group(pu), gv = group(pv);
        
        for(auto& r : rst[pv]) {
            if(gu.count(r))
                return false;
        }
        for(auto& r : rst[pu]) {
            if(gv.count(r))
                return false;
        }

        return true;
    }
    
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        N = n;
        for(auto& r : restrictions) {
            rst[r[0]].insert(r[1]);
            rst[r[1]].insert(r[0]);
        }
        for(int i = 0; i < n; i++) us[i].insert(uf[i] = i);
        
        vector<bool> res;
        for(auto& r : requests) {
            int u = r[0], v = r[1];
            if(deny(u, v)) {
                res.push_back(true);
                merge(u,v);
            } else res.push_back(false);
        }
        return res;
    }
};