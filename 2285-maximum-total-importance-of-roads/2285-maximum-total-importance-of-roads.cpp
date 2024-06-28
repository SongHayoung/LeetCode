class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> conn(n), w(n);
        for(auto& r : roads) {
            int u = r[0], v = r[1];
            conn[u]++;
            conn[v]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < n; i++) {
            pq.push({conn[i], i});
        }
        for(int i = 1; i <= n; i++) {
            auto [_, u] = pq.top(); pq.pop();
            w[u] = i;
        }
        long long res = 0;
        for(auto& r : roads) {
            int u = r[0], v = r[1];
            res += w[u] + w[v];
        }
        return res;
    }
};