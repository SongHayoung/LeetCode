class MinCostMaxFlow {
public:
    struct Edge { int v; long long cap, cost; int rev; };
    int N;
    vector<vector<Edge>> G;
    vector<long long> dist, pot;
    vector<pair<int,int>> pv;
    MinCostMaxFlow(int n): N(n), G(n), dist(n), pot(n), pv(n) {}

    void addEdge(int u, int v, long long cap, long long cost){
        Edge a{v, cap, cost, (int)G[v].size()};
        Edge b{u, 0,   -cost, (int)G[u].size()};
        G[u].push_back(a); G[v].push_back(b);
    }

    pair<long long,long long> minCostMaxFlow(int s, int t, long long need = (1LL<<62)){
        long long flow = 0, cost = 0;
        fill(pot.begin(), pot.end(), 0);
        while(flow < need){
            fill(dist.begin(), dist.end(), (long long)4e18);
            dist[s] = 0;
            priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
            pq.push({0, s});
            while(!pq.empty()){
                auto [d,u] = pq.top(); pq.pop();
                if(d != dist[u]) continue;
                for(int i=0;i<(int)G[u].size();i++){
                    auto &e = G[u][i];
                    if(e.cap <= 0) continue;
                    long long nd = d + e.cost + pot[u] - pot[e.v];
                    if(nd < dist[e.v]){
                        dist[e.v] = nd;
                        pv[e.v] = {u, i};
                        pq.push({nd, e.v});
                    }
                }
            }
            if(dist[t] == (long long)4e18) break; 

            for(int i=0;i<N;i++) if(dist[i] < (long long)4e18) pot[i] += dist[i];

            long long add = need - flow;
            int v = t;
            while(v != s){
                auto [u, idx] = pv[v];
                add = min(add, G[u][idx].cap);
                v = u;
            }
            v = t;
            while(v != s){
                auto [u, idx] = pv[v];
                auto &e = G[u][idx];
                auto &r = G[v][e.rev];
                e.cap -= add;
                r.cap += add;
                v = u;
            }
            flow += add;
            cost += add * pot[t];
        }
        return {flow, cost};
    }
};

class Solution {
public:
    long long minMoves(vector<int> balance) {
        int n = balance.size();
        long long S = accumulate(balance.begin(), balance.end(), 0LL);
        if(S < 0) return -1;
        bool anyNeg = false;
        for(int x: balance) if(x < 0) { anyNeg = true; break; }
        if(!anyNeg) return 0;

        int SS = n, TT = n+1;
        MinCostMaxFlow mcmf(n+2);

        for(int i=0;i<n;i++){
            int j = (i+1)%n;
            mcmf.addEdge(i, j, (long long)1e15, 1);
            mcmf.addEdge(j, i, (long long)1e15, 1);
        }
        long long need = 0;
        for(int i=0;i<n;i++){
            if(balance[i] > 0) mcmf.addEdge(SS, i, balance[i], 0);
            else if(balance[i] < 0){
                mcmf.addEdge(i, TT, - (long long)balance[i], 0);
                need += -(long long)balance[i];
            }
        }
        auto [f, c] = mcmf.minCostMaxFlow(SS, TT, need);
        return c;
    }
};