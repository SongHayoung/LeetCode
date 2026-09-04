
class Solution {
public:
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v,w});
        }
        vector<vector<long long>> times(n, vector<long long>(power + 1, LLONG_MAX));

        priority_queue<array<long long,3>,vector<array<long long,3>>, greater<>> q;
        auto push = [&](long long u, long long t, long long p) {
            if(p > power) return;
            if(times[u][p] <= t) return;
            times[u][p] = t;
            q.push({t,p,u});
        };
        push(source,0,0);
        while(q.size()) {
            auto [time, pow, u] = q.top(); q.pop();
            if(times[u][pow] != time) continue;
            for(auto& [v,w] : adj[u]) {
                push(v,time + w, pow + cost[u]);
            }
        }
        vector<long long> res{LLONG_MAX, LLONG_MAX};
        for(int pow = 0; pow <= power; pow++) {
            if(times[target][pow] == LLONG_MAX) continue;
            vector<long long> now{times[target][pow], power - pow};
            if(res[0] == now[0]) res = max(res, now);
            else res = min(res, now);
        }
        if(res[0] == LLONG_MAX) res = {-1,-1};
        return res;
    }
};