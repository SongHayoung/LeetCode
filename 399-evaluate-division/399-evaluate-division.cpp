class Solution {
    unordered_map<string, string> g;
    unordered_map<string, vector<pair<string, double>>> e;
    string find(string& s) {
        if(!g.count(s)) return g[s] = s;
        return __find(s);
    }
    string __find(string& s) {
        return g[s] == s ? s : g[s] = find(g[s]);
    }
    void uni(string& s1, string& s2) {
        string ps1 = find(s1), ps2 = find(s2);
        if(ps1 > ps2) {
            g[ps1] = g[ps2] = ps2;
        } else {
            g[ps1] = g[ps2] = ps1;
        }
    }
    void init(vector<vector<string>>& equations, vector<double>& values) {
        int n = equations.size();
        for(int i = 0; i < n; i++) {
            uni(equations[i][0], equations[i][1]);
            e[equations[i][0]].push_back({equations[i][1], values[i]});
            e[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }
    }
    double bfs(string from, string to) {
        if(from == to) return 1.0;
        queue<pair<string, double>> q;
        q.push({from, 1.0});
        unordered_set<string> v;
        v.insert(from);
        while(!q.empty()) {
            auto [str, mul] = q.front(); q.pop();
            for(auto [nxt, val] : e[str]) {
                if(v.count(nxt)) continue;
                if(nxt == to) return mul * val;
                q.push({nxt, mul*val});
                v.insert(nxt);
            }
        }
        return -1;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& q) {
        init(equations, values);
        int n = q.size();

        vector<double> res(n, -1.0);

        for(int i = 0; i < n; i++) {
            if(!g.count(q[i][0]) or !g.count(q[i][1])) continue;
            if(find(q[i][0]) != find(q[i][1])) continue;
            res[i] = bfs(q[i][0], q[i][1]);
        }

        return res;
    }
};