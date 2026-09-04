vector<vector<pair<long long, long long>>> mas, mis;
class Solution {
    
    long long dfs0(vector<vector<int>>& adj, int u, int par, vector<int>& A) {
        auto& ma = mas[u], &mi = mis[u];
        ma.clear();
        mi.clear();

        for (int v : adj[u]) {
            if (v == par) continue;

            long long sub = dfs0(adj, v, u, A);

            ma.push_back({sub, v});
            mi.push_back({sub, v});

            sort(mi.begin(), mi.end());
            sort(ma.rbegin(), ma.rend());

            while (mi.size() > 2) mi.pop_back();
            while (ma.size() > 2) ma.pop_back();
        }

        if (ma.empty()) return A[u];

        return ma[0].first - mi[0].first + A[u] + ma[0].first;
    }

    long long judge(vector<pair<long long, long long>>& mas,
                    vector<pair<long long, long long>>& mis,
                    int par,
                    long long parVal,
                    int skip,
                    int self) {
        long long ma = LLONG_MIN, mi = LLONG_MAX;
        for (auto& [val, v] : mis) {
            if (skip == v) continue;
            ma = max(ma, val);
            mi = min(mi, val);
        }

        for (auto& [val, v] : mas) {
            if (skip == v) continue;
            ma = max(ma, val);
            mi = min(mi, val);
        }

        if (par != -1) {
            ma = max(ma, parVal);
            mi = min(mi, parVal);
        }

        return ma == LLONG_MIN ? self : ma + ma - mi + self;
    }

    void dfs1(vector<vector<int>>& adj, int u, int par, long long parVal, vector<int>& A, long long& res) {
        res = min(res, judge(mas[u], mis[u], par, parVal, -1, A[u]));

        for (int v : adj[u]) {
            if (v == par) continue;

            long long now = judge(mas[u], mis[u], par, parVal, v, A[u]);

            dfs1(adj, v, u, now, A, res);
        }
    }

public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        mas.assign(n, {});
        mis.assign(n, {});

        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        long long res = dfs0(adj, 0, -1, baseTime);
        dfs1(adj, 0, -1, -1, baseTime, res);

        return res;
    }
};