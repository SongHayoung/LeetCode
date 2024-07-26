class Solution {
    vector<vector<int>> floydWarshall(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n, vector<int>(n, 987654321));
        for(auto e : edges) {
            g[e[1]][e[0]] = g[e[0]][e[1]] = min(g[e[0]][e[1]], e[2]);
        }
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(g[i][j] > g[i][k] + g[k][j]) {
                        g[i][j] = g[i][k] + g[k][j];
                    }
                }
            }
        }
        return g;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> g = floydWarshall(n, edges);
        
        int city = -1;
        int reachable = INT_MAX;
        for(int i = 0; i < n; i++) {
            int r = 0;
            for(int j = 0; j < n; j++) {
                if(j == i) continue;
                r += (g[i][j] <= distanceThreshold);
            }
            if(reachable >= r) {
                reachable = r;
                city = i;
            }
        }
        return city;
    }
};