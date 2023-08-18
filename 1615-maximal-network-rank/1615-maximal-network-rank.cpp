class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> r(n);
        vector<vector<bool>> adj(n,vector<bool>(n));
        for(auto& road : roads) {
            r[road[0]]++;
            r[road[1]]++;
            adj[road[0]][road[1]] = adj[road[1]][road[0]] = true;
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                res = max(res, r[i] + r[j] - adj[i][j]);
            }
        }
        return res;
    }
};