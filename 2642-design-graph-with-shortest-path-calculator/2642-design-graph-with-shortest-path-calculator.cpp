class Graph {
    vector<vector<long long>> c;
public:
    Graph(int n, vector<vector<int>>& edges) {
        c = vector<vector<long long>>(n, vector<long long>(n,INT_MAX));
        for(int i = 0; i < n; i++) c[i][i] = 0;
        for(auto e : edges) {
            long long u = e[0], v = e[1], w = e[2];
            c[u][v] = min(c[u][v], w);
        }
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
                }
            }
        }
    }

    void addEdge(vector<int> edge) {
        long long u = edge[0], v = edge[1], w = edge[2];
        c[u][v] = min(c[u][v], w);
        for(int i = 0; i < c.size(); i++) {
            for(int j = 0; j < c.size(); j++) {
                c[i][j] = min(c[i][j], c[i][u] + c[u][v] + c[v][j]);
            }
        }
    }

    int shortestPath(int node1, int node2) {
        return c[node1][node2] >= INT_MAX ? -1 : c[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */