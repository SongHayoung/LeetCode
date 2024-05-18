class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& E) {
        vector<int> deg(n);
        set<pair<int,int>> st;
        for(auto& e : E) {
            int u = e[0] - 1, v = e[1] - 1;
            st.insert({u,v});
            st.insert({v,u});
            deg[u]++, deg[v]++;
        }
        vector<int> c;
        for(int i = 0; i < n; i++) if(deg[i] & 1) c.push_back(i);
        if(c.size() & 1) return false;
        if(c.size() > 4) return false;
        if(c.size() == 0) return true;
        auto ok = [&](int a, int b, int c, int d) {
            return !st.count({a,b}) and !st.count({c,d});
        };
        if(c.size() == 2) {
            int u = c[0], v = c[1];
            if(!st.count({u,v})) return true;
            for(int i = 0; i < n; i++) {
                if(u == i or v == i) continue;
                if(ok(u,i,v,i)) return true;
            }
        }
        if(c.size() == 4) {
            if(ok(c[0],c[1],c[2],c[3])) return true;
            if(ok(c[0],c[2],c[1],c[3])) return true;
            if(ok(c[0],c[3],c[1],c[2])) return true;
        }
        
            return false;
    }
};