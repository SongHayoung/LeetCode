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
    
    void updateLazy(int u) {
        if(lazy.count(u)) {
            for(int i = 0; i < N; i++)
                if(find(i) == u and !us[u].count(i)) {
                    us[u].insert(all(us[i]));
                    rst[u].insert(all(rst[i]));
                }
            lazy.erase(u);
        }
    }
    
    unordered_set<int> group(int u) {
        updateLazy(u);
        return us[u];
    }
    
    bool disjoint(unordered_set<int>& A, unordered_set<int>& B) {
        if(A.size() > B.size())
            return disjoint(B,A);
        for(auto& a : A)
            if(B.count(a))
                return true;
        return false;
    }
    
    bool deny(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;
        auto gu = group(pu), gv = group(pv);
        
        if(disjoint(rst[pv], gu))
            return true;
        if(disjoint(rst[pu], gv))
            return true;

        return false;
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
            if(!deny(u, v)) {
                res.push_back(true);
                merge(u,v);
            } else res.push_back(false);
        }
        return res;
    }
};