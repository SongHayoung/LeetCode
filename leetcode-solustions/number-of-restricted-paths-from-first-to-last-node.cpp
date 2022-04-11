class Solution {
    long long memo[20001];
    int mod = 1e9 + 7;
private:
    void getDistance(unordered_map<int, list<pair<int, int>>>& g, vector<long>& dis, int n) {
        dis[n] = 0;
        priority_queue<pair<int, long>> pq;
        pq.push({n, 0});
        while(!pq.empty()) {
            int node = pq.top().first;
            long distance = -pq.top().second;
            pq.pop();
            if(dis[node] < distance) continue;
            for(auto& near : g[node]) {
                if(distance + near.second < dis[near.first]) {
                    dis[near.first] = distance + near.second;
                    pq.push({near.first, -(dis[near.first])});
                }
            }
        }
        return;
    }

    long long dfs(unordered_map<int, list<pair<int, int>>>& g, vector<long>& distance, int node, const int target) {
        if(memo[node] != -1)
            return memo[node];

        long long& cur = memo[node];
        cur = 0;
        for(auto& near : g[node]) {
            if(distance[node] > distance[near.first])
                cur += dfs(g, distance, near.first, target);
        }
        cur %= mod;
        return cur;
    }
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        unordered_map<int, list<pair<int, int>>> g;
        vector<long> distance(n + 1, INT_MAX);
        for(auto& edge : edges) {
            g[edge[0]].push_back({edge[1], edge[2]});
            g[edge[1]].push_back({edge[0], edge[2]});
        }

        getDistance(g, distance, n);
        memset(memo, -1, sizeof(memo));
        memo[n] = 1;
        return dfs(g, distance, 1, n) % mod;
    }
};
