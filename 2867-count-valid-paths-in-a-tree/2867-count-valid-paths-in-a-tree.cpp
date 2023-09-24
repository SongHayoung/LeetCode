
class Solution {
    vector<bool> prime;
    vector<long long> uf, cnt;
    long long find(int u) {
        return uf[u] == u ? u : uf[u] = find(uf[u]);
    }
    void uni(int u, int v) {
        long long pu = find(u), pv = find(v);
        cnt[pu] = cnt[pv] = cnt[pu] + cnt[pv];
        uf[pu] = uf[pv] = min(pu,pv);
    }
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        prime = vector<bool>(n + 1);
        cnt = uf = vector<long long>(n + 1);
        for(int i = 1; i <= n; i++) cnt[i] = 1, uf[i] = i;
        prime[0] = prime[1] = true;
        for(long long i = 2; i <= n; i++) {
            if(prime[i]) continue;
            for(long long j = i * i; j <= n; j += i) prime[j] = true;
        }
        vector<pair<long long, long long>> exc;
        for(auto e : edges) {
            int u = e[0], v = e[1];
            if(!prime[u] or !prime[v]) {
                if(!prime[u] and !prime[v]) continue;
                exc.push_back({u,v});
            } else {
                uni(u,v);
            }
        }
        long long res = 0;
        unordered_map<long long, long long> freq;
        for(auto& [u,v] : exc) {
            u = find(u), v = find(v);
            if(!prime[u]) {
                if(!freq.count(u)) freq[u] = 1;
                res += freq[u] * cnt[v];
                freq[u] += cnt[v];
            }
            if(!prime[v]) {
                if(!freq.count(v)) freq[v] = 1;
                res += freq[v] * cnt[u];
                freq[v] += cnt[u];
            }

        }
        return res;
    }
};

