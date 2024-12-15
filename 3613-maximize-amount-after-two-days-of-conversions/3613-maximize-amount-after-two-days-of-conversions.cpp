class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& currencyPairs1, vector<double>& rates1, vector<vector<string>>& currencyPairs2, vector<double>& rates2) {
        unordered_map<string, int> ord;
        int idx = 0;
        auto apply = [&](string& s) {
            if(ord.count(s)) return;
            ord[s] = idx++;
        };
        apply(initialCurrency);
        for(auto& p : currencyPairs1) for(auto& c : p) apply(c);
        for(auto& p : currencyPairs2) for(auto& c : p) apply(c);
        vector<double> dp(idx);
        dp[0] = 1.;
        auto run = [&](vector<vector<string>>& p, vector<double> r) {
            vector<vector<pair<int,double>>> adj(idx);
            priority_queue<pair<double,int>> q;
            for(int i = 0; i < p.size(); i++) {
                int u = ord[p[i][0]], v = ord[p[i][1]];
                assert(u != v);
                adj[u].push_back({v,r[i]});
                adj[v].push_back({u,1. / r[i]});
            }
            for(int i = 0; i < idx; i++) q.push({dp[i], i});
            while(q.size()) {
                auto [val, u] = q.top(); q.pop();
                
                if(dp[u] != val) continue;
                for(auto& [v,r] : adj[u]) {
                    double x = val * r;
                    if(dp[v] >= x) continue;
                    dp[v] = x;
                    q.push({dp[v],v});
                }
            }
        };
        run(currencyPairs1,rates1);
        run(currencyPairs2,rates2);
        return dp[0];
    }
};